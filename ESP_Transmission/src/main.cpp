/*There are AI generated code snippets, so there may be some errors. 
Please check the code before using it. Although mostly there isnt any error since it is already tested.*/

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Alpha"; //Replace with your SSID on the hotspot providing device
const char* password = "ikjh0650"; //Replace with your Password on the hotspot providing device
const char* serverURL = "http://192.168.137.1:8000/post-data"; /*replace the ip/port with the hotspot ip and port. The 'post-data' 
thing is an intermediate thing that need not be manually created anywhere.*/
WiFiClient client;
String postData;
int postVariable = 0;
int LED_BUILTIN = 2;


void setup() {
pinMode (LED_BUILTIN, OUTPUT);
WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  //This section is to be updated with the gesture detection code.
  //
digitalWrite(LED_BUILTIN, HIGH);
delay(500);
digitalWrite(LED_BUILTIN, LOW);
postVariable++;
postData = postVariable;
delay(1000);
// 
//
//The transmission section
//
if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "text/plain");
    // Send the POST request
    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();  
  }
//
//
}