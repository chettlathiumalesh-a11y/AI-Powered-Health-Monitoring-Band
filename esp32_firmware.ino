#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "MAX30105.h"

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
MAX30105 sensor;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  client.setServer(mqtt_server, 1883);
  sensor.begin();
}

void loop() {
  long heartRate = sensor.getHeartRate();
  long spo2 = sensor.getSpO2();
  String payload = "{\"heartRate\":" + String(heartRate) + ",\"spo2\":" + String(spo2) + "}";
  client.publish("healthband/data", payload.c_str());
  delay(1000);
}
