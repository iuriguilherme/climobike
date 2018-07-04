# Modelo de dados

Este arquivo é um modelo de como os dados devem ser armazenados no cartão SD

## Nomenclatura de arquivos

Para o ClimoBike 0.2.1, o minuto obtido do relógio deve determinar o nome do 
arquivo. Em caso de falha, um novo arquivo deve ser criado. Em caso de sucesso 
e contínua obtenção de dados, a cada hora um novo arquivo deverá ser criado.
Exemplo do sistema de arquivos em um caso onde às 18:17 um climobike foi 
ligado, sendo que às 18:23 aconteceu uma falha com o cartão, o climobike se 
recuperou e continuou gravando, funcionando normalmente até às 23:45 do mesmo 
dia:

    /dados/2018-07-03-18-17.txt
    /dados/2018-07-03-18-23.txt
    /dados/2018-07-03-18-33.txt
    /dados/2018-07-03-19-33.txt
    /dados/2018-07-03-20-33.txt
    /dados/2018-07-03-21-33.txt
    /dados/2018-07-03-22-33.txt
    /dados/2018-07-03-23-33.txt

Para o ClimoBike 0.2.2, desejavelmente a rotação do arquivo deve ser diária. 
Então o mesmo exemplo acima teria o seguinte resultado se ficasse rodando a 
semana toda:

    /dados/2018-07-03-18-17.txt
    /dados/2018-07-03-18-23.txt
    /dados/2018-07-03-18-33.txt
    /dados/2018-07-04-18-33.txt
    /dados/2018-07-05-18-33.txt
    /dados/2018-07-06-18-33.txt
    /dados/2018-07-07-18-33.txt

## Armazenamento

Os dados devem ser gravados em um arquivo no cartão SD conforme o padrão 
supracitado, de linha em linha e em formato de dicionário python de acordo com 
o padrão JSON.
Abaixo um exemplo identado para facilitar a compreensão, mas nos arquivos, 
todos dados devem estar em uma única linha, que deve ser gravada com somente o 
último caractere sendo newline.

    {
      "climobike" : "0.2.0.1",
      "json" : "0.1",
      "datetime" : "2018-07-03 18:00",
      "tmp" : "25.0",
      "hum" : "50.0",
      "ch4" : "4096",
      "no1" : "4096",
      "co1" : "4096",
      "gpsdate" : "2018-07-03 18:00:00:00",
      "gpslat" : "-30.04",
      "gpslng" : "-51.22",
      "gpssat" : "5",
      "gpshdop" : "535",
    }

### Legenda

- "climobike" : String, versão do ClimoBike;
- "json" : String, versão do modelo de dados;
- "datetime" : RTCDateTime, dados do DS1307;
- "tmp" : Float, temperatura em graus Celsius do DHT;
- "hum" : Float, umidade relativa do ar em (formato) do DHT;
- "ch4" : Float, (quantidade) de metano em (formato) do sensor MQ4;
- "no1" : Float, (quantidade) de (gás) em (formato) do sensor (nome);
- "co1" : Float, (quantidade) de monóxido de carbono em (formato) do sensor (nome);
- "gpsdate" : Datetime, dados do GPS (modelo);
- "gpslat" : Float, latitude, dados do GPS;
- "gpslng" : Float, longitude, dados do GPS;
- "gpssat" : Int, quantidade de satélites, dados do GPS;
- "gpshdop" : Int, HDOP, dados do GPS;

## API

Todos sistemas que usufruirem dos dados do climobike terão que respeitar o 
formato definido neste documento. Preferivelmente adaptar radicalmente o 
formato somente até a versão de produção do ClimoBike 0.2

