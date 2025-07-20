    #include "stationDefines.h"  // Project definitions
//------------------------------------------------------//    
    #include <ESP8266WiFi.h>
    WiFiClient client;
//------------------------------------------------------//    
   #include <SoftwareSerial.h>
// Set up a new SoftwareSerial object
  SoftwareSerial xbee_Serial(4, 0); // Rx,Tx
//------------------------------------------------------//    
//================== main setup ========================//
void setup() 
  {
        Serial.begin(9600);
        xbee_Serial.begin(9600);
        delay(10);
       
//----------------------------------------all sensors starts now       
      
//----------------------------------------connect WiFi
       WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
      {
        delay(60);
        Serial.print(".");
        delay(60);
        Serial.println("");
        Serial.println("WiFi not connected");
      }
        delay(100);
        Serial.println("");
        Serial.println("WiFi connected");
      
//----------------------------------------------------//
      
      
}

//------------------------------------------------------//
//================== main LOOP ========================//
void loop() 
{


//==========================================
  while(xbee_Serial.available()){
        inChar=xbee_Serial.read(); //((char) c);
        if(isprint( inChar)){
 //------------------------- 1ST TEST START ID  
     if(inChar == '$')
        { 
        ID_OK=1;     // IF ID OK FLAG ==1 
        }
     if(ID_OK==1){
       inputString += inChar;  // add it to the inputString:
 //-------------------------  TEST STOP ID    
     if(inChar == '#'){  
         ID_OK=0;  // IF ID OK FLAG ==0
         SMS_OK =1; // SMS OK FLAG ==1 
         break;
        }
      }
    }
  }

  if(SMS_OK ==1){

    SMS_OK =0;

    Serial.println("data recvd from xbee ");
    Serial.println(inputString);


     hum = inputString.substring(3, 7);
     Serial.println(temp);
     temp  = inputString.substring(8, 12);
     Serial.println(hum);
          
    inputString =" ";
    
  }




//============================================//
      unsigned long currentMillis2 = millis();
  if (currentMillis2 - previousMillis2 >= 6000) {
      previousMillis2 = currentMillis2;
 
//============================================//       
       
   if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
          {  

          String postStr = apiKey;
          postStr +="&field1=";
          postStr += String(temp); //   tempC value
          
          postStr +="&field2=";
          postStr += String(hum);  // tempF value
          


          
          postStr += "\r\n\r\n";
          
          client.print("POST /update HTTP/1.1\n");
          client.print("Host: api.thingspeak.com\n");
          client.print("Connection: close\n");
          client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
          client.print("Content-Type: application/x-www-form-urlencoded\n");
          client.print("Content-Length: ");
          client.print(postStr.length());
          client.print("\n\n");
          client.print(postStr);
        }
          client.stop();
       // thingspeak needs minimum 15 sec delay between updates
     }
     
   }
