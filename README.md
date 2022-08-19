# ESP32_AlexaTest
In this repository you will be able to control several devices using the ESP32 microcontroller and the Amazon Echo Dot Alexa. Both files were coded by Arduino IDE. 

It is divided into two sections, the first and second test. 
* The first one involves turning ON and OFF an LED by voice commands with the Alexa.
* The second test is related to control an AC by the Alexa and the ESP32. For this example is to turn ON and OFF the Air Conditioner.

To both tests the files needed are located in each binder according to the test.

# *** First Test: Turning ON and OFF an LED by the Alexa ***
To try the example, first, you need to open the _ESP32_AlexaTest_LED_ binder and load the _.ino_ file into the ESP32 microcontroller. Inside the code there is a link where you will be able to download the library to control the Alexa.
The code was commented to understand how it was written and how to apply it.

# *** Second Test: Turning ON and OFF an AC by the Alexa ***
**Part 1**

To try the example, first, you need to open the _ESP32_AlexaTest_AC_ then you will see there are two sub-binders. To control an Air Conditioner is needed to clone the original control by decoding its hexadecimal values and getting the bits quantity coming from the buttons you would like to clone.

In the binder _Arduino IR Receiver_Decoder_ you will find all the needed parts to clone the original AC control. It was decoded by a VS1838 sensor and the code is included in the files. Also, is required to download the library "PinDefinitionsAndMore.h". Because that is how the pins are defined to perform IR actions as an Input and Output depeding the microcontroller.

In the _.ino_ file I added the link to download for the IR_Remote library.

**Part 2**

In the second part, you need to open the _ESP32 AC_Test/ESP32_AlexaTest_AC_ and download it to be able to work on that code using the Arduino IDE. The "PinDefinitionsAndMore.h" is needed to be located in the same binder as the _.ino_ code to successfully upload the code into the ESP32. The pin that will be used to connect the IR diode will be the D4 in the ESP32, as the library establishes.

After uploading the codes in the ESP32 microcontroller, you need to connect your Amazon Echo Dot and the microcontroller to the same Wi-Fi network in order to let your Alexa find the devices you are creating with the codes. Also is important to set up the Alexa into "Search for devices" mode and it should automatically detect the LED or the AC. 

Finally that is all you need to be able to understand how you can be able to control any digital device by making voice commands to turn ON and OFF devices. With the Alexa library there is a maximum of 10 devices to create in the Alexa app.


