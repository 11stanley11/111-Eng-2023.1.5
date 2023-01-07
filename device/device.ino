#include "device.h"

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10); // 設定為每10毫秒結束一次讀取(數字愈小愈快)
  pinMode(3, OUTPUT); //馬達驅動初始
  digitalWrite(3, HIGH);
  initServo();  
  initMotor(); 
}

void loop() {
  readValue(); //讀值
  setServo(servo); 
  setMotor(motor);
  Serial.print("servo= ");
  Serial.println(173 - (90 - servo) / 2);
  Serial.print("motor= ");
  Serial.println(motor);
  delay(5000);
}
