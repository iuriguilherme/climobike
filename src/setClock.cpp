/*
setClock.ino
Gravador de relógio do Sistema de Automação PRISMA Ambiental
Código baseado nas bibliotecas DS1307 e Wire do Arduino IDE
Versão 1.0
Desenvolvido por Alisson Claudino ->  https://lief.if.ufrgs.br/~itsalissom
*/

#include <Wire.h>  //Inclusão de bibliotecas
#include <DS1307.h>

DS1307 clock;  //Inicialização de objetos de tipos relógio, data e Serial
RTCDateTime date;


void setup()
{
  clock.begin(); //Inicialização do relógio
  Serial.begin(9600); //Inicialização do Serial

  clock.setDateTime(__DATE__, __TIME__); //Grava a data atual do computador no relógio
  
}

void loop()
{
  date = clock.getDateTime(); //Obtém data atual
  Serial.print("Data Atual: ");
  Serial.print(date.year);   Serial.print("-");
  Serial.print(date.month);  Serial.print("-");
  Serial.print(date.day);    Serial.print(" ");
  Serial.print(date.hour);   Serial.print(":");
  Serial.print(date.minute); Serial.print(":");
  Serial.print(date.second); Serial.println("");
  Serial.println();
  delay(1000);
}
