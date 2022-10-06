#include <SoftwareSerial.h>

SoftwareSerial HC_05(10, 11); // RX | TX (D10, D11)

int randNumber;
char randNumberChar[2];
String randNumberStr;

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
      randNumber = random(1, 8);

      // https://geekmatic.in.ua/preobrazovanie_char_v_integer
      randNumberStr = String(randNumber);
      randNumberStr.toCharArray(randNumberChar, 2);
           
      sendDataForBluetooth(randNumber);
      HC_05.write(randNumber);
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
