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

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(L_Ena, OUTPUT);     
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  
  pinMode(R_Ena, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}


void forwards(int duration);
void backwards(int duration);
void fastStop(int duration);
void reset();

// the loop routine runs over and over again forever:
void loop()
{

  forwards(2000);
  reset();
  fastStop(1000);
  reset();
  backwards(2000);
  reset();
  
}







void forwards(int duration)
  {
    digitalWrite(L_Ena, HIGH);
    digitalWrite(L_Ena, HIGH);
    
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
    digitalWrite(L_Ena, HIGH);
     
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
  

