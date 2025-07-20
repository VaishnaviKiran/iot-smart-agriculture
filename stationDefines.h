
//====== confing WIFI & API KEY ======//
String apiKey = "2NWATPU6NZT10VIR";   //  Enter your Write API key from ThingSpeak
const char *ssid =  "Redmi";     // replace with your wifi ssid and wpa2 key
const char *pass =  "123456789";     
const char* server = "api.thingspeak.com";



String temp,hum;


 String inputString ="";
   int  SMS_OK,ID_OK=0;
   char inChar;
     
//======= confing  input/outputs ===========//
 

 


//---------------------------------------------for GPS & RTC time display on main loop
unsigned long previousMillis = 0;  // will store last time was updated
int ledState = LOW;                // ledState used to set the display mode rtc & gps
//========================================================
unsigned long previousMillis2 = 0; 
//=========================================//
