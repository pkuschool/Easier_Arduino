#include "arduino.h"
class port{
	public:
		byte port;
		byte status;
		void pmin();
		void pmout();
		void oti();
}
void pmin(byte a){
  pinMode(a,0x00);
}
void pmout(byte a){
  pinMode(a,0x01);
}
void otiwd(byte a=9,byte b=A0,int delaytime=50,double times=1.0){//output to input with delay;
  if(delaytime>0){
	int k1=analogRead(a);
	delay(delaytime);
	int k2=analogRead(a);
	analogWrite(b,((k1+k2)/2)*times);
  }else{
	  int k=analogread(a);
	  analogWrite(b,k*times);
  }
}