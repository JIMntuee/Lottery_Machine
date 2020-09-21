#include "possibility.h"
#define DELAY_TIME 50
#define TIMES_OF_SPIN 2
#define BUTTON 10
#define MAGIC_NUMBER 21

int pin[16] = {};
int count = 0; 
// count for MAGIC_NUMBER
// the MAGIC_NUMBER-th customer win the first prize

enum Mode{
  STOP = 0,
  HIGHSPEED = 1,
  SLOWDOWN = 2,
};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 16; i++){
    pin[i] = 23 + 2*i;
    pinMode(pin[i], OUTPUT);
  }
  pinMode(BUTTON, INPUT_PULLUP);
}

  Mode mode = STOP;
  int input = 0;
  bool teststop = true;

  
  
void loop() {
  input = digitalRead(BUTTON);
  if(input == 0 && mode == STOP)  mode = HIGHSPEED;
  switch(mode){
    case  STOP:  break;
    case  HIGHSPEED:  highspeed();  break;
    case  SLOWDOWN:  slowdown();
  }
}

void highspeed() {
  bool is_stop_current = false;
  bool is_stop_previous = true;
  bool quit = false;
  is_stop_current = digitalRead(BUTTON);
  is_stop_previous = is_stop_current;
  int i = 0; // index of current on LED
  while(!quit){
    is_stop_current = digitalRead(BUTTON);
    if(is_stop_previous && !is_stop_current){
      quit = true;
    }
    is_stop_previous = is_stop_current;
    digitalWrite(pin[i%16], HIGH);
    delay(DELAY_TIME);
    digitalWrite(pin[i%16], LOW);
    if(quit) { // spin to the last LED
      for(int j = (i+1)%16 ; j < 16; j++) {
        digitalWrite(pin[j], HIGH);
        delay(DELAY_TIME);
        digitalWrite(pin[j], LOW);
      }
    }
    i++;
  }
  mode = SLOWDOWN;
}

void slowdown(){
  count++;
  int result = getRandomResult();
  ////////////////
//  if(count == MAGIC_NUMBER){
//    result = 2;
//  }
  ////////////////
  //Serial.print(result);
  int moves = result + 16*TIMES_OF_SPIN;
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
      delay(DELAY_TIME + 5*i);
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

int getRandomResult(){
  randomSeed(millis());
  int x = random(BASE_NUMBER);
  int result = getprize(x);
  return result; //1~16
}

void test(){
  int pos[17] = {};
  int temp = 0;
  for(int i = 0; i < 500; i ++){
    temp = getRandomResult();
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

