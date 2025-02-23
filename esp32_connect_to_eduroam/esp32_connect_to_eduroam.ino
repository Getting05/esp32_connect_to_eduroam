#include <esp_wifi.h>
#include <WiFi.h>
#include <esp_wpa2.h>

const char *ssid = "eduroam";
#define EAP_IDENTITY "your_identity"
#define EAP_PASSWORD "your_password"

uint8_t counter = 0;
unsigned long previousMillsWiFi = 0;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.printf(ssid);

//wpa2

  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
    counter++;
    if (counter >= 60) {
      ESP.restart();
    }
  }
  Serial.println(F("connected!!!"));
  Serial.print(F("IP adress set: "));
  Serial.println(WiFi.localIP());
}
void loop() {

  //  Serial.print("good!");
}