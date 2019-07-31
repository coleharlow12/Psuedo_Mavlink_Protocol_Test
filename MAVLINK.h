#ifndef MAVLINK_RSSI
#define MAVLINK_RSSI

#include <stdint.h>
#include "Arduino.h"

const uint8_t MagicNumber = 0xFE;
#define MAVLINK_RSSI_ID 255
#define RADIO_MODEM 30
#define RIGHT_ANTENNA 68
#define LEFT_ANTENNA 69
#define RSSI_MSG_LENGTH 9 

typedef struct RSSI_Mavlink{
	uint8_t magicNum; 
	uint8_t length; 
	uint8_t sequenceNum;
	uint8_t sysID;
	uint8_t compID;
	uint8_t msgID;
	uint8_t RSSI_Mavlink;
	uint16_t checksum;
} RSSI_msg;

bool readRSSI(uint8_t *Buffer, RSSI_msg *MavMSG);
bool storeRSSI(uint8_t *Buffer, RSSI_msg *MavMSG);
void displayRSSIinfo(RSSI_msg MavMSG);

#endif