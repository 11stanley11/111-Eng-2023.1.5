#include <windows.h>
#include <math.h>

void keyPress(int virtual_key_code)
{ 
	// This structure will be used to create the keyboard
    // input event.
    INPUT ip;

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = virtual_key_code; // virtual-key code for the "virtual_key_code" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

void NumberPress(int num)
{
	if(num < 0) //judge if the need to put "-" at the front
	{
		keyPress(0xBD);
	}
	for(int i=log10(abs(num));i>=0;i--) //loop for digits time (from the first number to the last number)
	{
		int n = abs(num) / int(pow(10,i)) % 10; //take every single number out 
		switch(n) //keyPress for 0~9
		{
			case 0: 
				keyPress(0x30);
				break;
			case 1:
				keyPress(0x31);
				break;
			case 2:
				keyPress(0x32);
				break;
			case 3:
				keyPress(0x33);
				break;
			case 4:
				keyPress(0x34);
				break;
			case 5:
				keyPress(0x35);
				break;
			case 6:
				keyPress(0x36);
				break;
			case 7:
				keyPress(0x37);
				break;
			case 8:
				keyPress(0x38);
				break;
			case 9:
				keyPress(0x39);
				break;
		}
	}
}