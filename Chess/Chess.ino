#include <SoftwareSerial.h>

// Bluetooth name "CHESS_BOARD", pass 1234

SoftwareSerial HC_05(10, 11); // RX | TX (D10, D11)

unsigned long BoardSide1;  //A1 - первый бит, H4 - последний бит. 32 поля так как 4 байта.
unsigned long BoardSide2;  //A5 - первый бит, H8 - последний бит. 32 поля так как 4 байта.

// число 255 - это 1111 1111 (все поля первой вертикали заняты)

int randNumber;

byte outputData;
byte inputData;

void setup()
 {
 
  Serial.begin(9600);
  HC_05.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth is ready to pairing!");
  
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
      randNumber = random(1, 25);      
      sendDataForBluetooth(randNumber); // number is converting to byte and sending as char (alphabet) A = 1, B = 2, C = 3 ...;
    }
    
  }
  
  // Arduino send data for Bluetooth
  if (Serial.available())
  {
    outputData = Serial.read(); 
    sendDataForBluetooth(outputData);
  }
}

void sendDataForBluetooth(byte _data) {
  HC_05.write(_data);
}
