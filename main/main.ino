#include <ESP8266WiFi.h>
i
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#include <ArduinoJSON.h>

const char* ssid = "lomunyak";
const char* password = "Ilm..1703";

ESP8266WebServer server(80);l
SoftwareSerial megaSerial(2, 3); // RX, TX
u
void handleRoot() {
  server.send(200, "text/plain", "Hello from ESP8266!");
}
void setup() {
  Serial.begin(115200);
  megaSerial.begin(115200);
  while (!Serial) {
    // Wait for Serial to be ready
  }
  String jsonString = megaSerial.readStringUntil('\n');
    Serial.println("Received JSON string from Mega: " + jsonString);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // Start the mDNS responder
if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
   } 
  else {
    Serial.println("Error setting up MDNS responder!");
    }
  server.on("/", handleRoot);
  server.onNotFound([]() {
    server.send(404, "text/plain", "Not Found");
  });
  server.begin();
}
void loop() {
    server.handleClient();
}