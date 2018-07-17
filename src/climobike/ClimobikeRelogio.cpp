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

String ClimobikeRelogio::getDatetime()
{
	String date;
	actualtime = relogio.getDateTime();
	date += actualtime.year;
	date += "-";
	date += actualtime.month;
	date += "-";
	date += actualtime.day;
	date += "-";
	date += actualtime.hour;
	date += "-";
	date += actualtime.minute;
	return date;
}

int ClimobikeRelogio::getHour()
{
	actualtime=relogio.getDateTime();
	return (int)actualtime.hour;
}

int ClimobikeRelogio::getMinute()
{
	actualtime=relogio.getDateTime();
	return (int)actualtime.minute;
}

String ClimobikeRelogio::getTimeStamp()
{
	actualtime=relogio.getDateTime();
	String timestamp = "";
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
	return timestamp;
}

void ClimobikeRelogio::loopRelogio()
{

	Wire.beginTransmission(0x68);
	if (Wire.endTransmission() == 0)
	{
		 LogRelogio.log(getTimeStamp());
	}
	else
	{
		Serial.println("Deu ruim no relogio");
	}
}

	/* Grava a data atual do computador no momento da compilação no relógio */
	void ClimobikeRelogio::atualizaHora() {
		relogio.setDateTime(__DATE__, __TIME__);
	}
