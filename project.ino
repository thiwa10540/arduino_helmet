#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 7); // RX, TX

#include "DHT.h"

#define DHTPIN 9
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int data = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(9,INPUT);

  dht.begin();
}

void loop() {
  float t = dht.readTemperature();

  if(t>=33.00){
    digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
//  if (mySerial.available()) {
//    Serial.write(mySerial.read());
//    data = mySerial.read();
//    if(data == 1){
//        Serial.println("open");
//        Serial.println(data,DEC);
//    }else{
//        Serial.println("close");
//        Serial.println(data,DEC);
//      }
//  }
  if(digitalRead(3)==0){
     mySerial.write("0");
     delay(500);
   }
}
