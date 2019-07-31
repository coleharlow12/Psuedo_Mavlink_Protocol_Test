#include "MAVLINK.h"

uint8_t buffer[9];
RSSI_msg TESTmsg;

void setup() {
  Serial1.begin(56700);
  Serial.begin(9600);
  Serial1.flush();

}

void loop() {
  if(readRSSI(buffer,&TESTmsg))
  {
    displayRSSIinfo(TESTmsg);
  }
}
