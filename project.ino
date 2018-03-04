#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 7); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(3,INPUT);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if(digitalRead(3)==0){
     mySerial.write("0");
     delay(500);
   }
}
