#include <Thermistor.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

Thermistor temp(5);

void setup (){
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop (){
  readTemp();
}

void readTemp(){
  if(mySerial.available() > 0){
    String leitura = mySerial.readString();
    if(leitura== "TMP"){
      int temperatura = temp.getTemp();
      mySerial.write(temperatura);
      Serial.println(temperatura);
    }
  }
}
