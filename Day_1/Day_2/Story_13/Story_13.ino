/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

#include <NewPing.h>

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 //was 350 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 

int L_Ena = 9;
int In1 = 8;
int In2 = 7;

int R_Ena = 10;
int In3 = 12;
int In4 = 11;

int LMF = 2;
int RMF = 3;

int ping_distance = 0;

int LSL = 0;
int LSM = 0;
int LSR = 0;

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
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  
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
void standardForward(void);



// the loop routine runs over and over again forever:
void loop()
{
  delay(50);    // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  ping_distance = sonar.ping_cm();
  //Serial.print("Ping: ");
  Serial.print(ping_distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  //Serial.println("cm");
  
  
   if (ping_distance > 20) //20
        {
            delay(200);//200
  
            LSL = analogRead(14);
            LSM = analogRead(15);
            LSR = analogRead(16);
            
            if ( (LSL < LSM) && (LSL < LSR) )
                 {
                    Serial.println();
                    Serial.print("Left sensor stronger");
                    turnLeft(1);
                 }
            else if ( (LSR < LSM) && (LSR < LSL) )
                 {
                    Serial.println();
                    Serial.print("Right sensor stronger");
                    turnRight(1);
                 }  
  
            else 
                {
                   Serial.println();
                   Serial.print("Middle sensor stronger");
                   forward_pulse(1);
                }  
       }
 
   else
   
       { 
          Serial.print("Fast stopped.");
          fastStop(100000);
          reset();
          while (1);
       }


}

void turnLeft (int userTurn)
{
      analogWrite (L_Ena, 0);
      analogWrite (R_Ena, 0);
      
      right_counter = 0;
      
   
      while(right_counter < userTurn)
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
      
       left_counter = 0;
      
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
    analogWrite(L_Ena, 0);
    analogWrite(R_Ena, 0);
    
    left_counter = 0;
    
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
  
 void standardForward()
  { 
    analogWrite(L_Ena, 220);
    analogWrite(R_Ena, 255);
    
    digitalWrite(In1, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In4, LOW);
  }
  

