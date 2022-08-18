//************* Made by Alan Lopez B. using the ESP32 microcontroller *************
//************* 07/03/2022 *************

#ifdef ARDUINO_ARCH_ESP32               //Here the algorithm goes into a conditional loop to identify which microcontroller is being used
#include <WiFi.h> 
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>                   //This library was downloaded in this link: https://github.com/Aircoookie/Espalexa 

int LED_INDC = 2;                       //This LED is being used a Wi-fi detector, when it starts to blink it means the ESP32 is looking for the SSID and when it is connected, it turns off
int LED_Test = 18;                      //This LED will be turned on and off with the Alexa commands

const char* ssid = "YourSSID";          //Type your SSID and Password, this microcontroller supports 2.4GHz Wi-Fi networks
const char* password = "YourPassword";

Espalexa alexapro;                      //The object called alexapro will be used to create the loop to control the device
void LED_TestV(uint8_t brightness);     //This function involves the command to turn on and off the device we will add, in this case the LED


void setup() {
 Serial.begin(115200);
 pinMode(LED_INDC, OUTPUT);
 pinMode(LED_Test, OUTPUT);
 WificonnectionV();
 alexapro.addDevice("YourDeviceName",LED_TestingF);  //Here you type how the device will appear in the Amazon Alexa app
 alexapro.begin();
}

void loop() {
  WificonnectionV();                                 //In this case the Wi-fi void will be applied in case the microcontroller is being turned off and on
  alexapro.loop();
  delay(1);
}

void WificonnectionV(){
  if(WiFi.status() != WL_CONNECTED){
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);
        Serial.println("");
        Serial.println("Connecting to WiFi");
    while(WiFi.status() != WL_CONNECTED){
      digitalWrite(LED_INDC, 1);
      delay(500);
      digitalWrite(LED_INDC, 0);
      delay(500);
      Serial.print(".");
      }
        Serial.print("Connected to ");               //When the ESP32 is connected to the Wi-Fi network it will turn off the LED which was used as the connection detector
        Serial.println(ssid);
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
  }

  void LED_TestingF(uint8_t brightness){             //This void is the basis to turn on and off any device we want to apply, in this case the LED.
    Serial.print("LED_Test status ");
      if(brightness){
      digitalWrite(LED_Test, 1);
      Serial.print("The LED is ON \n");
      }
        else{
      digitalWrite(LED_Test, 0);
      Serial.print("The LED is OFF \n");
        }
    }
