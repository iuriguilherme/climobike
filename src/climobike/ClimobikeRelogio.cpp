#include "ClimobikeRelogio.hpp"

void ClimobikeRelogio::setupRelogio() {
	LogRelogio.logSerial("Tentando iniciar Relógio...");
	relogio.begin();
	LogRelogio.logSerial(" deu ");
	Wire.beginTransmission(0x68);
	if (Wire.endTransmission() == 0) {
		relogio.begin();
		LogRelogio.logSerial("certo");
	    //    Serial.print("Atualizando hora...");
	    //    atualizaHora();
	    //    Serial.println(" feito!");
	} 
	else 
	{
		LogRelogio.logSerial("errado");
	}
	LogRelogio.logSerialLn("!");
} 

void ClimobikeRelogio::loopRelogio() {
	String timestamp = "";
	timestamp += "{";
	timestamp += "timestamp";
	timestamp += ":";
	timestamp += "'";

	Wire.beginTransmission(0x68);
	if (Wire.endTransmission() == 0) {
		actualtime = relogio.getDateTime();
		if ((int)actualtime.year > 0) {
			timestamp += actualtime.year;
			timestamp += "-";
			timestamp += actualtime.month;
			timestamp += "-";
			timestamp += actualtime.day;
			timestamp += " ";
			timestamp += actualtime.hour;
			timestamp += ":";
			timestamp += actualtime.minute;
			timestamp += ":";
			timestamp += actualtime.second;
			timestamp += " ";
			timestamp += "(";
			timestamp += actualtime.unixtime;
			timestamp += ")";
		}
		} else {
	        timestamp += EPOCH; //mentira
	    }

	    timestamp += "'";
	    timestamp += "}";
	    LogRelogio.log(timestamp);
	}

	/* Grava a data atual do computador no momento da compilação no relógio */
	void ClimobikeRelogio::atualizaHora() {
		relogio.setDateTime(__DATE__, __TIME__);
	}