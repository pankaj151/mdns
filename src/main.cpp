#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WiFiMulti.h>   // Include the Wi-Fi-Multi library
#include <ESP8266Ping.h>
#include <SoftwareSerial.h>

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
const char* remote_host = "amazon.com";

void setup() {
  Serial.begin(9600);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  wifiMulti.addAP("Aarushi", "P@ssw0rd1");   // add Wi-Fi networks you want to connect to
 // wifiMulti.addAP("Suvam", "suvam@7788");
 // wifiMulti.addAP("SIMMI", "09876543");
 // wifiMulti.addAP("A-155, phase-1", "63446344");
 // wifiMulti.addAP("Plavokac", "qwertyuiop");

  Serial.println("Connecting ...");
}

void loop() { 
  
 // int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(1000);
    Serial.print(':-<');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer
  Serial.print("Pinging host ");
  Ping.ping(remote_host);
  Serial.println(remote_host);
    Serial.println("Success!!");
    Serial.println();
}