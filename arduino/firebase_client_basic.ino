
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>



/* 1. Define the WiFi credentials */
#define WIFI_SSID "YOUR WIFI NETWORK"
#define WIFI_PASSWORD "YOUR WIFI PASSWORD"

/* 2. If work with RTDB, define the RTDB URL and database secret */
#define DATABASE_URL "LINK TO RTDB" 
#define DATABASE_SECRET "SECRET OF RTDB"

/* 3. Define the Firebase Data object */
FirebaseData fbdo;

FirebaseJson json;


int count = 0;

void setup()
{

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(DATABASE_URL, DATABASE_SECRET);
  Firebase.reconnectWiFi(true);

}

void loop()
{
        //use the path to the variable you want to read/update
        Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/firebaseIOT/sensor_1/status", count++) ? "ok" : fbdo.errorReason().c_str());
        delay(2000);
}
