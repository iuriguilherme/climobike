#include "ClimobikeGPS.hpp"
#include <string>

  HardwareSerial ss(1);
  String ClimobikeGPS::dadosGps() {
    String dadosGpsString = "";
    while (ss.available() > 0) {
      gps.encode(ss.read());

    }
    if (gps.location.isUpdated()) {
      latitude = gps.location.lat();
      longitude = gps.location.lng();
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
      dadosGpsString += latitude;
      dadosGpsString += ",";
      dadosGpsString += "longitude";
      dadosGpsString += ":";
      dadosGpsString += longitude;
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

String ClimobikeGPS::getLatitude()
{
  char buffer[11];
  String out;
  if(gps.location.isValid())
  {
    sprintf(buffer,"%.6lf",gps.location.lat());
    out=String(buffer);
  }
  Serial.print("\n\n\n");
  Serial.print(out);
  Serial.print("\n\n\n");
  return out;
}

String ClimobikeGPS::getLongitude()
{
  char buffer[11];
  String out;
  if(gps.location.isValid())
  {
    sprintf(buffer,"%.6lf",gps.location.lng());
    out=String(buffer);
  }
  Serial.print("\n\n\n");
  Serial.print(out);
  Serial.print("\n\n\n");
  return out;
}

  String ClimobikeGPS::loopGps() {
    String nossosDadosGps = dadosGps();
    if (nossosDadosGps != "") {
      Serial.println(nossosDadosGps);
      return nossosDadosGps;
    }
    else
      return "";
  }
