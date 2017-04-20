#include <Arduino.h>
#include "etools.h"

void eTimeToStr(String &str, long val, bool fullPrint){  
  int days = elapsedDays(val);
  int hours = numberOfHours(val);
  int minutes = numberOfMinutes(val);
  int seconds = numberOfSeconds(val);

  if (fullPrint || days) {
    str = String(days) + "d ";  
  }
  if (fullPrint || hours) {
    str += String(hours) + "h ";  
  }
  if (fullPrint || minutes) {
   str += String(minutes) + "m ";
  }
  str += String(seconds) + "s";
}

void BufferToString(String & str, const char* buf, int len) {
  str.reserve(len + 1); // set internal String buffer length
  // bug in lib! strcpy instead of strncpy!!!! WString.cpp#L176
  for (int i = 0; i < len; i++) {
    str.concat(buf[i]);
  }  
}


