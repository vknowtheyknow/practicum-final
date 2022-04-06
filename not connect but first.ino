#include<Servo.h>
//PB0 1 2 3 //PD0 1 5 6 
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

const int button11Pin = PIN_PB3;  
const int button12Pin = PIN_PB4; 
const int button13Pin = PIN_PB5; 
     
const int button21Pin = PIN_PC0;     
const int button22Pin = PIN_PC1; 
const int button23Pin = PIN_PC2; 


Servo servol11;
Servo servol12;
Servo servol13;
Servo servol21;
Servo servol22;
Servo servol23;
// variables will change:
int button11State;        
int button12State; 
int button13State; 
int button21State;
int button22State; 
int button23State; 
int state1;
int state2;
int winner;
int Round = 0;

//usbMsgLen_t usbFunctionSetup(uint8_t data[8]){
//    usbRequest_t *rq = (usbRequest_t*)data;
//    static uint8_t winner;
void setup() {
  pinMode(button11Pin, INPUT_PULLUP);
  pinMode(button12Pin, INPUT_PULLUP);
  pinMode(button13Pin, INPUT_PULLUP);
  pinMode(button21Pin, INPUT_PULLUP);
  pinMode(button22Pin, INPUT_PULLUP);
  pinMode(button23Pin, INPUT_PULLUP);
  servol11.attach(PIN_PB0);
  servol12.attach(PIN_PB1);
  servol13.attach(PIN_PB2);
  servol21.attach(PIN_PD0);
  servol22.attach(PIN_PD1);
  servol23.attach(PIN_PD5);
  servol11.write(0);
  servol12.write(0);
  servol13.write(0);
  servol21.write(0);
  servol22.write(0);
  servol23.write(0);

  
}

void loop() {
//   read the state of the pushbutton value:
  state1 = 0;
  state2 = 0;
  button11State = digitalRead(button11Pin);//B
  button12State = digitalRead(button12Pin);
  button13State = digitalRead(button13Pin);
  button21State = digitalRead(button21Pin);//C
  button22State = digitalRead(button22Pin);
  button23State = digitalRead(button23Pin);
  //user1
  while(state1 == 0){
  if(button11State == LOW){
    servol11.write(0);
    state1 = ROCK;
  }
  else if(button12State == LOW){
    servol12.write(0);
    state1 = PAPER;
  }
  else if(button13State == LOW){
    servol13.write(0);
    state1 = SCISSORS;
  }
  else{
      servol11.write(90);
      servol12.write(90);
      servol13.write(90);
  }
  }
  //user2
  while(state2 == 0){
  if(button21State == LOW){
    servol21.write(0);
    state2 = ROCK;
  }
  else if(button22State == LOW){
    servol22.write(0);
    state2 = PAPER;
  }
  else if(button23State == LOW){
    servol23.write(0);
    state2 = SCISSORS;
  }
  else{
      servol21.write(90);
      servol22.write(90);
      servol23.write(90);
  }
  }
//  else if(button11Sta
  delay(500);


//find winner each round
  if(state1 == state2)
    winner = 0;
  else if(state1 == ROCK and state2 == PAPER)
    winner = 2;
  else if(state1 == ROCK and state2 == SCISSORS)
    winner = 1;
  else if(state1 == PAPER and state2 == ROCK)
    winner = 1;
  else if(state1 == PAPER and state2 == SCISSORS)
    winner = 2;  
  else if(state1 == SCISSORS and state2 == ROCK)
    winner = 2;
  else if(state1 == SCISSORS and state2 == PAPER)
    winner = 1;  
  

}
