#include <ArduinoUnit.h>

bool is_leap_year(int year)
  {
    return ((year % 4 == 0) && (year % 100 != 0))
    || (year % 400 == 0);
  }

test(a_typical_common_year_returns_false)
  {
    assertFalse(is_leap_year(2001));
  }


test(a_typical_leap_year_returns_true)
  {
    assertTrue(is_leap_year(1996));
  }
    
    
test(an_atypical_common_year_returns_false)
 {
   assertFalse(is_leap_year(1900));
 }
    
test(an_atypical_leap_year_returns_true)
 {
    assertTrue(is_leap_year(2000));
 } 
 
void setup() 
{
     // put your setup code here, to run once:
   Serial.begin(115200);
   
 }

void loop() 
 {
  // put your main code here, to run repeatedly: 
  Test::run();
 }
