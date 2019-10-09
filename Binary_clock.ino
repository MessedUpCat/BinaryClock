  
#include <Wire.h>
#include "RTClib.h"
RTC_Millis rtc;

void setup() {

  Serial.begin(57600);
  rtc.begin(DateTime(__DATE__, __TIME__));
  for (int i = 2; i <= 11; i++) 
    pinMode(i, OUTPUT);
}

void loop() {

  DateTime now = rtc.now();
   int x = now.minute();
  int y = now.hour();
  for (int temp = 2; temp <= 11; temp++) 
    digitalWrite(temp, LOW);
    
  if (y > 12) 
    y = y - 12;

  Serial.print(y, DEC);
  Serial.println();
  Serial.print(x, DEC);
  Serial.println();
  
  for (int temp = 0; temp <= 5; temp++) {
    if (x & 1 << temp) 
      digitalWrite((temp + 2), HIGH);
  }
  for (int temp = 0; temp <= 3; temp++) {
    if (y & 1 << temp) 
      digitalWrite((temp + 8), HIGH);
  }
  delay(500);
}
