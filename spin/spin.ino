#include "possibility.h"
#define delay_time 50
#define timesofspin 2
#define BUTTOM 10
#define surprise 21

int pin[16] = {};
int count = 0;

enum Mode{
  STOP = 0,
  HIGHSPEED = 1,
  SLOWDOWN = 2,
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 16; i++){
    pin[i] = 23 + 2*i;
    pinMode(pin[i], OUTPUT);
  }
  pinMode(BUTTOM, INPUT_PULLUP);
}

  Mode mode = STOP;
  int input = 0;
  bool teststop = true;

  
  
void loop() {
  
  input = digitalRead(BUTTOM);
  if(input == 0 && mode == STOP)  mode = HIGHSPEED;
  switch(mode){
    case  STOP:  break;
    case  HIGHSPEED:  highspeed();  break;
    case  SLOWDOWN:  slowdown();
  }
  /////////////////////////////
  //test();
}

void highspeed(){
  
  bool stop_c = false;
  bool stop_pr = true;
  bool quit = false;
  stop_c = digitalRead(BUTTOM);
  stop_pr = stop_c;
  int i = 0;
  while(!quit){
    stop_c = digitalRead(BUTTOM);
    if(stop_pr && !stop_c){
      quit = true;
    }
    stop_pr = stop_c;
    digitalWrite(pin[i%16], HIGH);
    delay(delay_time);
    digitalWrite(pin[i%16], LOW);
    if(quit){
      for(int j = (i+1)%16 ; j < 16; j++){
        //Serial.print("test");
        digitalWrite(pin[j], HIGH);
        delay(delay_time);
        digitalWrite(pin[j], LOW);
      }
    }
    i++;
  }
  mode = SLOWDOWN;
  //delay(10000);
}

void slowdown(){
  count++;
  Serial.print(count);
  int result = testpos();
  ////////////////
//  if(count == surprise){
//    result = 2;
//  }
  ////////////////
  //Serial.print(result);
  int moves = result + 16*timesofspin;
  for (int i = 0; i < moves; i++){
    if(i >= moves - 3){
      digitalWrite(pin[i%16], HIGH);
      delay(500);
      digitalWrite(pin[i%16], LOW);
    }
    else if(i == moves - 4){
      digitalWrite(pin[i%16], HIGH);
      delay(350);
      digitalWrite(pin[i%16], LOW);
    }
    else{
      digitalWrite(pin[i%16], HIGH);
      delay(delay_time + 5*i);
      digitalWrite((pin[i%16]), LOW);
    }
  }
  flash(result-1);
}

void flash(int i){
  digitalWrite(pin[i], HIGH);
  delay(500);
  for(int j = 0; j < 4; j ++){
    digitalWrite(pin[i], HIGH);
    delay(500);
    digitalWrite(pin[i], LOW);
    delay(500);
  }
  digitalWrite(pin[i], HIGH);
  delay(5000);
  digitalWrite(pin[i], LOW);
  mode = STOP;
}

int testpos(){
  randomSeed(millis());
  int x = random(base_number);
  int result = getprize(x);
  return result;//1~16
}

void test(){
  int pos[17] = {};
  int temp = 0;
  for(int i = 0; i < 500; i ++){
    temp = testpos();
    delay(20);
    pos[temp]++;
  }
  for(int i = 1; i < 17; i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(pos[i]);
    Serial.print('\n');
  }
  
}

