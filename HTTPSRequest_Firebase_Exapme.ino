/*
    HTTP over TLS (HTTPS) example sketch

    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.

    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1

    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WiFiMulti.h>

const char* ssid = "xyz";
const char* password = "abc1234567";

const char* host = "abc.firebaseio.com";
const int httpsPort = 443;
// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "6F D0 9A 52 C0 E9 E4 CD A0 D3 02 A4 B7 A1 92 38 2D CA 2F 26";

// Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  ESP8266WiFiMulti wifiMulti;
  int preVal;
  
void setup() {
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(0, LOW); 
  digitalWrite(2, LOW); 
  int preVal=0;
  Serial.begin(115200);
  //wifi setup
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("zxc", "abc12345");
  wifiMulti.addAP("dff", "abc12345");
  wifiMulti.addAP("demo", "abc12345");
  
  //connecting to server
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }
  
  //digitalWrite(0, LOW);    
}

void loop() {
//  digitalWrite(2, LOW); 
//  digitalWrite(0, LOW);
 if(wifiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
  }
  else{
    if(!client.connected()){
      client.connect(host, httpsPort);
      Serial.println("WiFi not connected!");
      client.verify(fingerprint, host);
    }
    else{
      Serial.println("WiFi connected!");
       String url = "/user.json?print=pretty";
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: keep-alive\r\n\r\n");
        while (client.connected()) {
          String line = client.readStringUntil('\n');
          if (line == "\r") {
            break;
          }
        }
        String line = client.readStringUntil('\n');
        int newVal = line.toInt(); 
          if(newVal!=preVal){
              if(newVal==1){
                Serial.println("inside 1");
                digitalWrite(2, HIGH);
                digitalWrite(0, LOW); 
              }
              else if(newVal==2){
                digitalWrite(0, HIGH);
                digitalWrite(2, LOW);
                Serial.println("inside 2");
              }else{
                digitalWrite(2, LOW);
                digitalWrite(0, LOW); 
                Serial.println("inside others");
              }
               preVal=newVal;
            }
        
           //Serial.println("preval . "+preVal +"new Val"+newVal);
        }
   }   
}
