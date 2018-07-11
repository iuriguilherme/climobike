#include "ClimobikeLog.hpp"

void ClimobikeLog::logSerial(String mensagem) 
{
	Serial.print(mensagem.c_str());
}
void ClimobikeLog::logSerialF(char * mensagem, String formato) 
{
	Serial.printf(mensagem, formato.c_str());
}
void ClimobikeLog::logSerialLn(String mensagem) 
{
	Serial.println(mensagem.c_str());
}
void ClimobikeLog::log(String mensagem) 
{
	logSerialLn(mensagem);
}
void ClimobikeLog::log(char * mensagem, String formato) 
{
	logSerialF(mensagem, formato);
}