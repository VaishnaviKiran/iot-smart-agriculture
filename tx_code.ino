#include "DHTesp.h"
DHTesp dht;


#include <SoftwareSerial.h>


SoftwareSerial xbee_Serial(4, 0); // Rx,Tx


void setup()
{
Serial.begin(9600);
xbee_Serial.begin(9600);     // bluetooth module baudrate 



Serial.println();
Serial.println("Status\t\tHumidity (%)\t\tTemperature (C)\t");
dht.setup(14, DHTesp::DHT11); // GPIO14

}
      void loop()
      {
      //delay(dht.getMinimumSamplingPeriod() + 100);
      delay(1500);
      float humidity = dht.getHumidity();
      float temperature = dht.getTemperature();
      Serial.print("Status: ");
      Serial.print(dht.getStatusString());
      Serial.print("\t");
      Serial.print("Humidity (%): ");
      Serial.print(humidity, 1);
      Serial.print("\t");
      Serial.print("Temperature (C): ");
      Serial.print(temperature, 1);
      Serial.print("\t");
      Serial.println();
//=========================send values to xbee rx 
      xbee_Serial.print("$");  
      xbee_Serial.print("H");     
      xbee_Serial.print(humidity, 1);
      xbee_Serial.print("T");
      xbee_Serial.print(temperature, 1);
      xbee_Serial.println("#");  



}
