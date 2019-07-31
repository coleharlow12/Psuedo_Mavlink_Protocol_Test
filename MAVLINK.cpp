#include "Arduino.h"
#include "MAVLINK.h"

bool readRSSI(uint8_t *Buffer, RSSI_msg *MavMSG){
	//Used to iterate through the entire message. Since it is static it retains its value between calls
	static int count = 0;

	//Holds the size in bytes of the structure RSSI_Mavlink
	while( Serial1.available()){
		//reads a single byte of data
		if (count == 9)
		{
			count = 0;
			storeRSSI(Buffer, MavMSG);
			return(true);
		}
		else
		{
		Buffer[count] = Serial1.read();
		count++;
		}

	}
	return(false);
}

bool storeRSSI(uint8_t *Buffer, RSSI_msg *MavMSG){
	for(int i = 0; i <= 8; ++i)
	{
		//Serial.println((Buffer[i]));
		((byte*)(MavMSG))[i]= Buffer[i];
	}
	Serial.println("Message Read");

}

void displayRSSIinfo(RSSI_msg MavMSG){
	Serial.println(MavMSG.magicNum);
	Serial.println(MavMSG.length);
	Serial.println(MavMSG.sequenceNum);
	Serial.println(MavMSG.sysID);
	Serial.println(MavMSG.compID);
	Serial.println(MavMSG.msgID);
	Serial.println(MavMSG.RSSI_Mavlink);
	Serial.println(MavMSG.checksum);
}
