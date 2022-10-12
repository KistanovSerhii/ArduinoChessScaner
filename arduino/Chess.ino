#define _OPEN_SYS_ITOA_EXT
#include <stdio.h>
#include <stdlib.h>

#include <SoftwareSerial.h>

// Bluetooth name "CHESS_BOARD", pass 1234

SoftwareSerial HC_05(10, 11); // RX | TX (D10, D11)

unsigned int Multiplexer12 = 0xffff;  // Опрашивает линию 1-2. 16 полей так как 2 байта.
unsigned int Multiplexer34 = 0;       // Опрашивает линию 3-4. 16 полей так как 2 байта.
unsigned int Multiplexer56 = 0;       // Опрашивает линию 5-6. 16 полей так как 2 байта.
unsigned int Multiplexer78 = 0xffff;  // Опрашивает линию 7-8. 16 полей так как 2 байта.

uint64_t MultiplexersCommonData; // Результат опроса всей доски.

byte outputData;
byte inputData;

// for test
int randNumber;
bool StartingPositionOfClassicalChess = true;

void setup()
 {
 
  Serial.begin(9600);
  HC_05.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth is ready to pairing!");

}

void calculateMultiplexersCommonData(unsigned int multiplexer, int shift = 0) {
    
  MultiplexersCommonData |= multiplexer;
  MultiplexersCommonData <<= shift;

}

void loop()
{

  // get data from some device
  if (HC_05.available())
  {
    // inputData = HC_05.read();
    //Serial.write(inputData);
    
    String inputStr = HC_05.readString();
    Serial.println(inputStr);

    inputStr.trim();
    if (inputStr == "test")
    {
      sendRandomMultiplexersCommonDataForBluetooth();
    }

    if (inputStr == "startposition")
    {
      Multiplexer12 = 65535;
      Multiplexer34 = 0;
      Multiplexer56 = 0;
      Multiplexer78 = 65535;

      calculateMultiplexersCommonData(Multiplexer12, 16);
      calculateMultiplexersCommonData(Multiplexer34, 16);
      calculateMultiplexersCommonData(Multiplexer56, 16);
      calculateMultiplexersCommonData(Multiplexer78, 0);

      sendbyteDataForBluetooth(MultiplexersCommonData);
      MultiplexersCommonData = 0;
    }    
    
  }
  
  // Arduino send data for Bluetooth
  if (Serial.available())
  {
    outputData = Serial.read(); 
    sendbyteDataForBluetooth(outputData);
  }
}

void sendbyteDataForBluetooth(byte _data) {
  HC_05.write(_data);
}

void sendCharsDataForBluetooth(char* _data) {
  HC_05.write(_data);
}

void sendRandomMultiplexersCommonDataForBluetooth() {

  Multiplexer12 = random(1, 65535);
  Multiplexer34 = random(1, 65535);
  Multiplexer56 = random(1, 65535);
  Multiplexer78 = random(1, 65535);

  calculateMultiplexersCommonData(Multiplexer12, 16);
  calculateMultiplexersCommonData(Multiplexer34, 16);
  calculateMultiplexersCommonData(Multiplexer56, 16);
  calculateMultiplexersCommonData(Multiplexer78, 0);
  
  char buffer [sizeof(uint64_t)*8+1];

  // convert number to array chars.
  ultoa(MultiplexersCommonData, buffer, HEX);
  
  sendCharsDataForBluetooth(buffer);
  MultiplexersCommonData = 0;

}
