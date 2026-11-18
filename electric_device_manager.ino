#include <Arduino.h>
#include <KiwisIoT.h>

// Wi-Fi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Dashboard Topic
const char* topic = "YOUR_DASHBOARD_TOPIC";

KiwisIoT kiwisiot(ssid, pass, topic);

// Relay Pins
#define RELAY1 D1
#define RELAY2 D2

// Active LOW Relay Module
#define RELAY_ON LOW
#define RELAY_OFF HIGH

void onControl(String ch, String val) {

  ch.trim();
  val.trim();

  if (val != "1" && val != "0") {
    return;
  }

  bool turnOn = (val == "1");

  // Relay 1 - Channel 0
  if (ch == "0") {
    digitalWrite(RELAY1, turnOn ? RELAY_ON : RELAY_OFF);

    Serial.println(turnOn ? "Relay 1 ON" : "Relay 1 OFF");
  }

  // Relay 2 - Channel 1
  else if (ch == "1") {
    digitalWrite(RELAY2, turnOn ? RELAY_ON : RELAY_OFF);

    Serial.println(turnOn ? "Relay 2 ON" : "Relay 2 OFF");
  }
}

void setup() {

  Serial.begin(115200);

  // Initial Relay State - OFF
  digitalWrite(RELAY1, RELAY_OFF);
  digitalWrite(RELAY2, RELAY_OFF);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  Serial.println("Starting Dual Relay Control");

  // Initialize KiwisIoT
  kiwisiot.begin();
}

void loop() {

  // Maintain KiwisIoT Connection
  kiwisiot.run();
}