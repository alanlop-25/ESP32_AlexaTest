//************* Made by Alan Lopez B. using the ESP32 microcontroller *************
//************* 14/05/2022 *************

#ifdef ARDUINO_ARCH_ESP32               //Here the algorithm goes into a conditional loop to identify which microcontroller is being used
#include <WiFi.h> 
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>                   //This library was downloaded in this link: https://github.com/Aircoookie/Espalexa 


#include "PinDefinitionsAndMore.h"      //According to the library is needed to use the D4 pin from the ESP32 to be the one which connects to the IR LED
#include <IRremote.hpp>                 //This library was downloaded in this link: https://github.com/Arduino-IRremote/Arduino-IRremote

int LED_INDC = 2;                       //This LED is being used a Wi-fi detector, when it starts to blink it means the ESP32 is looking for the SSID and when it is connected, it turns off
int LED_Test = 18;                      //This LED will be turned on and off with the Alexa commands

const char* ssid = "YourSSID";          //Type your SSID and Password, this microcontroller supports 2.4GHz Wi-Fi networks
const char* password = "YourPassword";

Espalexa alexapro;                          //The object called alexapro will be used to create the loop to control the device
void FunctionLED_Test(uint8_t brightness);   //This will be the function to turn on and off an LED by the Alexa
void FunctionAC_Test(uint8_t brightness);    //This will be the function to send different IR hex values through the IR LED by the Alexa

//Se crea el objeto IR para enviar 
IRsend irsend;                              //The object called irsend will be used to send the hex values through the IR LED

void setup() {
 Serial.begin(115200);
 pinMode(LED_INDC, OUTPUT);
 pinMode(LED_Test, OUTPUT);
 conectarWifi();
 alexapro.addDevice("LED Device",FunctionLED_Test);    //Here you type how the device will appear in the Amazon Alexa app
 alexapro.addDevice("AC Device",FunctionAC_Test);      //Here you type how the device will appear in the Amazon Alexa app
 alexapro.begin();
 IrSender.begin();
}

void loop() {
  conectarWifi();                                     //In this case the Wi-fi void will be applied in case the microcontroller is being turned off and on
  alexapro.loop();
  delay(1);
}

void conectarWifi(){
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

  void FunctionLED_Test(uint8_t brightness){ //This void is the basis to turn on and off any device we want to apply, in this case the LED and there is a serial print to corroborate the function.
    Serial.print("Function LED_Test - ");
      if(brightness){
      digitalWrite(LED_Test, 1);            //This command will turn ON the LED
      Serial.print("The LED is ON \n");
      }
        else{
      digitalWrite(LED_Test, 0);
      Serial.print("The LED is OFF \n");            //This command will turn OFF the LED
        }
    }

  void FunctionAC_Test(uint8_t brightness){  //This void is the basis to turn on and off any device we want to apply, in this case the AC.
    Serial.print("Function AC_Test - ");
      if(brightness){
      IrSender.sendNEC(0x8800909, 28);      //ON from the AC and the sctructure is: "0xHEX, CantidadBits", this is an example of how it has to be typed the hex value coming from the ON button and the bit quantity is displayed.
      Serial.print("The AC is ON \n");
      }
        else{
      IrSender.sendNEC(0x88C0051, 28);      //OFF from the AC and the sctructure is: "0xHEX, CantidadBits"
      Serial.print("The AC is OFF \n");
        }
       delay(200);
    }
