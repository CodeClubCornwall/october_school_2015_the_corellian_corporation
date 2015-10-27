/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int L_Ena = 9;
int In1 = 7;
int In2 = 8;

int R_Ena = 10;
int In3 = 11;
int In4 = 12;

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

// the loop routine runs over and over again forever:
void loop() {
  //Turning on Enabler pins.
  digitalWrite(L_Ena, HIGH);
  digitalWrite(R_Ena, HIGH);
  
  //Motor forwards
  digitalWrite(In1, HIGH);
  digitalWrite(In3, HIGH);
  
  //Ensure off for truth table
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
  
  delay(10000);
  
  
  //Fast stop
  digitalWrite(L_Ena, HIGH);
  digitalWrite(R_Ena, HIGH);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
  
  delay(2000);
  //Fast stop end
  
  
  
   //Start reverse
  digitalWrite(L_Ena, HIGH);
  digitalWrite(R_Ena, HIGH);
 
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  
  digitalWrite(In2, HIGH);
  digitalWrite(In4, HIGH);
  
  delay(10000);
  
  
  
  
}
