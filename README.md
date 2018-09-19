# Smart IOT Car

This project is for IOT beginners. It gives an idea how to control a toy car over internet. It can be applied to control/tagged any dumb device over internet or can be enhanced for better control. Before jump into code, developer should have sound knowledge in ESP 8266, Arduino Uno Board,Firebase, Ionic Mobile App and basic Electronics.​

## ESP 8266

I have used ESP 8266-01 (AI thinker i.e black board) module for project. how ever you can chose any type. It is quite simple board having 8 Pins and very limited I/O pins. if your project needs more no of pins check type of board you may need [HERE](https://en.wikipedia.org/wiki/ESP8266)

## Arduino board

Arduino used for uploading sketch file to ESP8266 and debugging purposes.

## Circuit Diagram
First download Arduino IDE, Download sketch file and compile. If it gives error . please check your IDE settings.
Tools>Board> Generic ESP8266 Module. Programmer> depend what type you are using. For me AVRISP.

Connect ESP8266 as per the below description.No extra setup required. I am using GPIO0 and GPIO2 as output to control Car remote.
<ul>
  <li>VCC->3.5V.</li>
  <li>CH_PD: Chip enable. Keep it on high (3.3V) for normal operation.</li>
  <li>RST: Reset. Keep it on high (3.3V) for normal operation</li>
  <li>GND->GND.</li>
  <li>RX->RX Arduino</li>
  <li>TX-> TX Arduino</li>
  <li>
    #####Normal Mode(Running Mode)
    GPIO0 and GPIO2 ->high
  </li>
  <li>
    ##### programming Mode
    GPIO0 ->GND
    GPIO2 ->high
  </li>
</ul>
## Hosting Firebase server
<ul>
  <li>Create project at https://console.firebase.google.com/.</li>
  <li>go to Database >realtime Database.</li>
  <li>create a none name "user", your ESP8266 will get data from this node of server.</li>
  <li>don't enable anytype of authentication as of now. you can change sketch file if you want authentication enabled.</li>
</ul>

## Android Application setup
<ul>
  <li>Clone the repository</li>
  <li>Goto firebase console again, get your project config (for web client). project overview>project settings >Add Firebase to your web app.</li>
  <li>Update same in firebaseConfig in app.module.ts.</li>
  <li>Run below commands for Android Application</li>
  <li>cd SmartCar</li>
  <li>npm install</li>
  <li>ionic cordova platform add android</li>
  <li>ionic cordova run android</li>
</ul>

## Program ESP8266
Clone the repository, Find HTTPSRequest_Firebase_Exapme.ino. Wire up Arduino and ESP8266. you can use 3.5v output of Arduino.
Don't use 5V, it can fry up your ESP module.
#### Things to notice.(programming Mode)
GPIO0 ->GND
GPIO2 ->high
Arduino IDE>Board>Generic ESP8266 Module.</br>
if you are getting errors like

#### esp_com open failed error: Failed to open COM33 ,error: espcomm_open failed, error: espcomm_upload_mem failed
check programming mode connection is correctly done or not.
Once you have programmed Esp, blue led(if its available) will blink and you are done with ESP programming.

## Running end-to-end tests
Power up your all mlodule, open android application. click button and watch output of GPIO0 and GPIO2 in Arduino Monitor. I have skipped wiring of Car remote, because its upto you what appliance you want to feed it.

## Further help
https://www.hackster.io/ROBINTHOMAS/programming-esp8266-esp-01-with-arduino-011389
https://www.instructables.com/id/How-to-use-the-ESP8266-01-pins/
