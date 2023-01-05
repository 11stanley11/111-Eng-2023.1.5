#define SERVO_PIN 10 //伺服馬達腳位
int Port[2] = {5, 7}; //馬達腳位

#include <Servo.h>

Servo myservo;

void initServo() {
  myservo.attach(SERVO_PIN);
  myservo.write(173); //初使角度
  delay(500);
}

void setServo(int Elevation_angle) {
  int Position_angle = 173 - (90 - Elevation_angle) / 2; //計算伺服馬達角度
  myservo.attach(SERVO_PIN);
  myservo.write(Position_angle);
  delay(600);
  myservo.detach();
}

void initMotor() {
  pinMode(Port[0], OUTPUT);
  pinMode(Port[1], OUTPUT);
}

void setMotor(int sita) {
  int speed = -140,temp=0,fi=sita-temp;
  if(fi>0){ //當旋轉角度為正 馬達正轉
    analogWrite(Port[0], abs(speed));
    digitalWrite(Port[1], HIGH);
    delay(fi * 17.9+300);
  }
  else if(fi<0){ //當旋轉角度為負 馬達反轉
    analogWrite(Port[0], speed);
    digitalWrite(Port[1], LOW);
    delay(fi * 17.9+300);
  }
  analogWrite(Port[0], 0);
}

int servo = 90,motor = 0;
bool sequent = false;
int readValue() {
  String num = "";
  int i = 0 ;
  int temp_servo,temp_motor;
  bool in = false;
  while (Serial.available()) { //如果有輸入 則進行紀錄
    if (i == 0) {
      num = "";
    }
    num += Serial.read() - 48; // -48是要將ASC II 碼轉換為數字
    i++;
    in = true;
  }
  String servo_s = num.substring(0,num.indexOf('-')); //尋找 "space"(ASCII -16) 以分割字串 因輸入的數字只有正數 所以找 "-" 以判斷
  String motor_s = num.substring(num.indexOf('-')+3,num.length());
  temp_servo = servo_s.toInt();
  temp_motor = motor_s.toInt();
  if(temp_servo < 0){ //將負的ASCII碼 -3 轉換 -
    servo_s.setCharAt(1, '0'); //將字串的第二個位置(字元是3)轉換為0
    temp_servo = servo_s.toInt();
  }
  if(temp_motor < 0){ //將負的ASCII碼 -3 轉換 -
    motor_s.setCharAt(1, '0'); //將字串的第二個位置(字元是3)轉換為0
    temp_motor = motor_s.toInt();
  }
  i = 0 ;
  if(in){ //如果有輸入 才改數據 否則保持
    servo = temp_servo; 
    motor = temp_motor;
  }
}
