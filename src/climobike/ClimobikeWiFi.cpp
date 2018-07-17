#include "ClimobikeWiFi.hpp"

void ClimobikeWiFi::setupWifi() {
      Serial.print("Tentando iniciar Wifi");
      Serial.print(" em ");
      Serial.print(networkName);
      Serial.print(" com ");
      Serial.print(networkPswd);

      WiFi.begin(networkName, networkPswd);
      while (WiFi.status() == WL_IDLE_STATUS) {
        delay(1000);
        Serial.print(".");
      }

      Serial.println();
    }

    void ClimobikeWiFi::loopWifi() {
      switch (WiFi.status()) {
        case WL_CONNECTED:
          Serial.println("assigned when connected to a WiFi network");
          break;
        case WL_NO_SHIELD:
          Serial.println("assigned when no WiFi shield is present");
          break;
        case WL_IDLE_STATUS:
          Serial.println("it is a temporary status assigned when WiFi.begin() is called and remains active until the number of attempts expires (resulting in WL_CONNECT_FAILED) or a connection is established (resulting in WL_CONNECTED)");
          break;
        case WL_NO_SSID_AVAIL:
          Serial.println("assigned when no SSID are available");
          break;
        case WL_SCAN_COMPLETED:
          Serial.println("assigned when the scan networks is completed");
          break;
        case WL_CONNECT_FAILED:
          Serial.println("assigned when the connection fails for all the attempts");
          break;
        case WL_CONNECTION_LOST:
          Serial.println("assigned when the connection is lost");
          break;
        case WL_DISCONNECTED:
          Serial.println("assigned when disconnected from a network");
          break;
        default:
          Serial.println("nunca deveria aparecer isto");
      }
      delay(3000);
    }
