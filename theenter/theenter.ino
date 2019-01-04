#include <fastpin.h>
byte com[1]={';'};
byte ret[1]={0xb0};
byte cpy[2]={0x80,'c'};
byte pst[2]={0x80,'v'};
byte inputport[4]={0,1,2,3};
byte outputport[3]={8,9,13};
bool music = false;
int n = 90;
int t = 90;

void setup() {
  // put your setup code here, to run once:
  pmin(inputport,4);
  pmout(outputport,2);
  servoinit(true,true,true,500);
  
  attachInterrupt(2, comma, RISING);
  attachInterrupt(3, sendreturn, RISING);
  servow();
  
  
  /* Code without fastpin.h
   * pinMode(0,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(8,OUTPUT);
  Servo up;Servo down;
  down.attach(9);
  up.attach(10);
  down.write(180);
  up.write(180);
  delay(1000);
  down.write(0);
  up.write(0);
  delay(1000);
  pinMode(13,OUTPUT);*/
 }

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(0)){
    paste();
  }
  if(digitalRead(1)){
    copy();
  }
  if(digitalRead(2)&&digitalRead(3)){
    music = !music;
   }

}

void comma(){
  keypress(com);
  if(music){
    tone(9,300);
    delay(50);
    noTone(9);
  }
}
void sendreturn(){
  keypress(ret);
  if(music){
    tone(9,500);
    delay(50);
    noTone(9);
  }
}
void copy(){
  keypress(cpy,2);
  /*Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.end();
   */ 
}

void paste(){
  keypress(pst,2);
}
