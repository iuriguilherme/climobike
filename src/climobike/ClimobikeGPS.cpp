#include "ClimobikeGPS.hpp"
  
  HardwareSerial ss(1);
  String ClimobikeGPS::dadosGps() {
    String dadosGpsString = "";
    while (ss.available() > 0) {
      gps.encode(ss.read());
    }
    if (gps.location.isUpdated()) {
      dadosGpsString += "{";
      dadosGpsString += "date";
      dadosGpsString += ":";
      dadosGpsString += gps.date.value();
      dadosGpsString += ",";
      dadosGpsString += "time";
      dadosGpsString += ":";
      dadosGpsString += gps.time.value();
      dadosGpsString += ",";
      dadosGpsString += "speed";
      dadosGpsString += ":";
      dadosGpsString += gps.speed.mps();
      dadosGpsString += ",";
      dadosGpsString += "altitude";
      dadosGpsString += ":";
      dadosGpsString += gps.altitude.meters();
      dadosGpsString += ",";
      dadosGpsString += "latitude";
      dadosGpsString += ":";
      dadosGpsString += gps.location.lat();
      dadosGpsString += ",";
      dadosGpsString += "longitude";
      dadosGpsString += ":";
      dadosGpsString += gps.location.lng();
      dadosGpsString += ",";
      dadosGpsString += "satellites";
      dadosGpsString += ":";
      dadosGpsString += gps.satellites.value();
      dadosGpsString += ",";
      dadosGpsString += "hdop";
      dadosGpsString += ":";
      dadosGpsString += gps.hdop.value();
      dadosGpsString += ",";
      dadosGpsString += "}";
    }
    return dadosGpsString;
  }

  void ClimobikeGPS::setupGps() {
    /* Escolher UMA dessas opções */
    /* SoftwareSerial */
    //ss.begin(gpsBaud);
    /* HardwareSerial */
    ss.begin(gpsBaud, SERIAL_8N1, gpsRxPin, gpsTxPin, false);

    Serial.print("Tentando iniciar GPS com ");
    Serial.print(gpsBaud);
    do {
      Serial.print(".");
      delay(1000);
    } while (false);
    if (!(ss.available() > 0)) {
      Serial.print(" não ");
    }
    Serial.println(" deu certo!");
  }

  void ClimobikeGPS::loopGps() {
    String nossosDadosGps = dadosGps();
    if (nossosDadosGps != "") {
      Serial.println(nossosDadosGps);
    }
  }