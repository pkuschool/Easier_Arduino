#include "arduino.h"
#include <Servo.h>
#include "Keyboard.h"
Servo nine;
Servo ten;
void pmin(byte a[],int length){
  for(int i=0;i<length;i++){
	pinMode(a[i],0x00);
  }
  
}
void pmout(byte a[],int length){
  for(int i=0;i<length;i++){
	pinMode(a[i],0x01);
  }
}
void otiwd(byte a=9,byte b=A0,int delaytime=50,double times=1.0){//output to input with delay;
  if(delaytime>0){
	int k1=analogRead(a);
	delay(delaytime);
	int k2=analogRead(a);
	analogWrite(b,((k1+k2)/2)*times);
  }else{
	  int k=analogRead(a);
	  analogWrite(b,k*times);
  }
}
void servoinit(bool nineenabled=false,bool tenenabled=false,bool mechanicinit=false,int mechanicdelay=1000){
	if(nineenabled)nine.attach(9);
	if(tenenabled)ten.attach(10);
	if(mechanicinit){
		if(nineenabled)nine.write(0);
		if(tenenabled)ten.write(0);
		delay(mechanicdelay);
		if(nineenabled)nine.write(180);
		if(tenenabled)ten.write(180);
		delay(mechanicdelay);
	}
	
}
void servow(int nineang = 90,int tenang = 90){
	if(nineang!=-1)nine.write(nineang);
	if(tenang!=-1)ten.write(tenang);
}
void keypress(byte a[],int count=1,int holdtime=50,bool takeover=true){
  if(takeover)Keyboard.begin();
  for(int i=0;i<count;i++){
    Keyboard.press(a[i]);
  }
  delay(holdtime);
  
  if(takeover){
    Keyboard.releaseAll();
    Keyboard.end();
  }else{
    for(int i=0;i<count;i++){
    Keyboard.release(a[i]);
    }
  }
}
