#include <SoftwareSerial.h>
#include <stdio.h>

// Bluetooth +
// name "CHESS_BOARD", pass 1234
SoftwareSerial HC_05(10, 11); // RX | TX (D10, D11)
byte outputData;
byte inputData;
// Bluetooth -

// rfid +
SoftwareSerial rfid(9, 8); // RX, TX
int rfidDataChar = 0; // 2 - start data, 3 - end data.
int rfidCounter = 0;
char rfidDataBuf[11];
// rfid -

void setup()
 {
 
  Serial.begin(9600); // serial port PC
  HC_05.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  rfid.begin(9600);   // Модуль RDM6300
  Serial.println("The bluetooth is ready to pairing!");

}

void loop()
{

  if (rfid.available() > 0) 
  {
    rfidDataChar = rfid.read();

    if (rfidDataChar < 3) {
      strncpy(rfidDataBuf,"",11);
      rfidCounter = 0;  
    }

    // if (rfidDataChar == 3) {
    if (strlen(rfidDataBuf) == 12) {
      //rfidDataBuf[rfidCounter] = '\0'; завершение строки
      Serial.println(rfidDataBuf);
      strncpy(rfidDataBuf,"",11);
      rfidCounter = 0;      
    }

    if (rfidDataChar > 3) {
      rfidDataBuf[rfidCounter] = (char) rfidDataChar;
      rfidCounter++;
    }
  }

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
      Serial.println("test");
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