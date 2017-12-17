#include <ESP8266WiFi.h>

void wifi_init() {
  Serial.print("connecting to wifi: ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);  
  wifi_wait_for_connected();

  Serial.println("connected to wifi");
}

void wifi_wait_for_connected(){
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();  
}

void wifi_print_info(){
  Serial.print("wifi ssid: ");
  Serial.println(WiFi.SSID());

  Serial.print("wifi ip: ");
  Serial.println(WiFi.localIP());

  byte mac[6];  
  WiFi.macAddress(mac);
  Serial.print("wifi mac: ");
  
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
}

