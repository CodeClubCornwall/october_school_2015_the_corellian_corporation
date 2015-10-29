/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int L_Ena = 9;
int In1 = 8;
int In2 = 7;

int R_Ena = 10;
int In3 = 12;
int In4 = 11;

int LMF = 2;
int RMF = 3;

volatile int left_counter = 0;
volatile int right_counter = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(L_Ena, OUTPUT);     
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  
  pinMode(R_Ena, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  attachInterrupt (0, left_increment, RISING);
  attachInterrupt (1, right_increment, RISING);
  digitalWrite (2, HIGH);
  digitalWrite(3, HIGH);
  Serial.begin (115200);
  int i = 0;
  int userTurn = 0;
}

void forward_time(int duration);
void backwards(int duration);
void fastStop(int duration);
void reset();
void left_increment(void);
void right_increment(void);
void forward_pulse(int pulse);
void turnRight (int userTurn);
void turnLeft (int userTurn2);




// the loop routine runs over and over again forever:
void loop()
{   //right loop
    int i;
  for(i=0; i<3; i++)
    {
      left_counter = 0;
      right_counter = 0;
    
      forward_pulse(240);
         
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
      
      turnRight(150);
    }
    
    left_counter = 0;
    right_counter = 0;
    
    reset();
    
//Middle straight code    
forward_pulse(480);
fastStop(1000);

left_counter = 0;
right_counter = 0;

turnLeft(170);//160 before 200 too much 

fastStop(1000);



left_counter = 0;
right_counter = 0;

forward_pulse(240);
       
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
      
      turnLeft(170);
    
   
    left_counter = 0;
    right_counter = 0;
    
    forward_pulse(240);
    fastStop(1000);
    reset();
   
   turnLeft(170);
      
      left_counter = 0;
      right_counter = 0;
       
      forward_pulse(240);
       
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
      
     // turnLeft(160);
   
   
   // left_counter = 0;
  //  right_counter = 0;
    
   // forward_pulse(290);
   // fastStop(1000);
    reset();
   
   
   while(1);
   
}







void turnLeft (int userTurn2)
{
      analogWrite (L_Ena, 0);
      analogWrite (R_Ena, 0);
      
      right_counter = 0;
      
   
      while(right_counter < userTurn2)
        {
          analogWrite (R_Ena, 255);
          analogWrite (L_Ena, 0);
          
          digitalWrite(In1, LOW);
          digitalWrite(In3, HIGH);
          digitalWrite(In2, LOW);
          digitalWrite(In4, LOW);
          
        }
}    

void turnRight (int userTurn)
{
      analogWrite (L_Ena, 0);
      analogWrite (R_Ena, 0);
      
   
      while(left_counter < userTurn)
        {
          analogWrite (L_Ena, 255);
          analogWrite (R_Ena, 0);
          
          digitalWrite(In1, HIGH);
          digitalWrite(In3, LOW);
          digitalWrite(In2, LOW);
          digitalWrite(In4, LOW);
          
        }
} 








void left_increment() {
   left_counter ++;
   }
   
void right_increment() {   
   right_counter ++;
}



void forward_pulse(int pulse)
  {
    
    while(left_counter < pulse)
      {
        analogWrite(L_Ena, 235);
        analogWrite(R_Ena, 255);
    
        digitalWrite(In1, HIGH);
        digitalWrite(In3, HIGH);
        digitalWrite(In2, LOW);
        digitalWrite(In4, LOW);
      }
  }




void forward_time(int duration)
  {
    analogWrite(L_Ena, 220);
    analogWrite(R_Ena, 255);
    
    digitalWrite(In1, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In4, LOW);
    delay(duration);
  }



void backwards(int duration)
  {
    
    digitalWrite(L_Ena, HIGH);
    digitalWrite(L_Ena, HIGH);
     
    digitalWrite(In1, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In4, HIGH);
    delay(duration);
  }     
     

void fastStop(int duration)
  {
    digitalWrite(L_Ena, HIGH);
    digitalWrite(R_Ena, HIGH);
     
    digitalWrite(In1, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In2, HIGH);
    digitalWrite(In4, HIGH);
    delay(duration);
  }
  
    
void reset()
  {
      digitalWrite(L_Ena, LOW);
    digitalWrite(L_Ena, LOW);
     
    digitalWrite(In1, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In4, LOW);
  }  
  
  
  

