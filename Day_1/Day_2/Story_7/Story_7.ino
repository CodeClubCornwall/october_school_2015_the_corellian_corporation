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
  Serial.begin (115200);
  int i = 0;
  int userTurn = 0;
}

void forwards(int duration);
void backwards(int duration);
void fastStop(int duration);
void reset();
void left_increment(void);
void right_increment(void);
void forward(void);
void turnRight (int userTurn);

// the loop routine runs over and over again forever:
void loop()
{
 
      left_counter = 0;
      right_counter = 0;
     
      while(left_counter < 290)
       {
          forward();
       }
         
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
     
      turnRight(160);
   
      reset();
    
     left_counter = 0;
      right_counter = 0;
     
      while(left_counter < 290)
       {
          forward();
       }
         
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
     
      turnRight(160);
   
      reset();
    

   
    left_counter = 0;
      right_counter = 0;
     
      while(left_counter < 290)
       {
          forward();
       }
         
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
     
      turnRight(160);
   
      reset();
    

   
    left_counter = 0;
      right_counter = 0;
     
      while(left_counter < 290)
       {
          forward();
       }
         
      fastStop(1000);
       
      left_counter = 0;
      right_counter = 0;
   
      reset();
    

   while(1);
   
   
   
    
   

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
          digitalWrite(In3, HIGH);
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



void forward(void)
  {
    analogWrite(L_Ena, 235);
    analogWrite(R_Ena, 255);
    
    digitalWrite(In1, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In4, LOW);
  }




void forwards(int duration)
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
  
  
  

