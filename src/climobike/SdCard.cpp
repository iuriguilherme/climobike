#include "SdCard.hpp"

ClimobikeLog Log;
File arquivo;
/* Escreve no cartão de memória */
void SdCard::escreve(const char * mensagem, String nome) 
{
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  File arquivo = SD.open(nome, FILE_WRITE);
  Serial.printf("Escrevendo %s no arquivo: %s\n", mensagem, nome.c_str());
  if (!arquivo) 
  {
    Log.log("Erro tentando abrir o arquivo!");
  } 
  else if (arquivo.println(mensagem)) 
  {
    Log.log("Arquivo gravado no cartão!");
  }
  else 
  {
    Log.log("Erro tentando escrever no arquivo!");
  }
  arquivo.close();
}

File SdCard::escreveLinhaAbreArquivo(String nome)
{
  arquivo = SD.open(nome.c_str(), FILE_WRITE);
  return arquivo;
}

bool SdCard::escreveLinhaFechaArquivo(File arquivo)
{
  arquivo.close();
  return !arquivo;
}

void SdCard::escreveLinha(const char * mensagem, File arquivo) 
{
  if (!arquivo) 
  {
    Log.log("Erro tentando abrir o arquivo!");
  } 
  else if (arquivo.print(mensagem)) 
  {
    Log.log("Arquivo gravado no cartão!");
  } 
  else 
  {
    Log.log("Erro tentando escrever no arquivo!");
  }
}

void SdCard::setupSd() 
{
  Log.log("Tentando iniciar cartão SD...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  
  if (!SD.begin()) 
  {
    Log.log("Falhou tentando inicializar cartão SD!");
  } 
  
  else if (SD.cardType() == CARD_NONE) 
  {
    Log.log("Nenhum cartão SD detectado!");
  } 
  else 
  {
    Serial.print("\nSucesso! Tipo de cartão: ");
    if (SD.cardType() == CARD_MMC) 
    {
      Serial.print("MMC");
    }
    else if (SD.cardType() == CARD_SD) 
    {
      Serial.print("SDSC");
    }
    else if (SD.cardType() == CARD_SDHC) 
    {
      Serial.print("SDHC");      
    } 
    else 
    {
      Serial.print("UNKNOWN");
    }
    Serial.println(".");
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("Tamanho do cartão: %lluMB\n", cardSize);
    arquivo=escreveLinhaAbreArquivo("/climobikeraw.dat");
  }
} 

void SdCard::loopSd(String dado) 
{
  
  String gravarDados = "";
  gravarDados += "tempo=";
  gravarDados += millis();

  Serial.println("Testando escrita no cartão...");
  /* TODO testar cartão para ver se está funcionando aqui, e tratar erros */
  escreveLinha(dado.c_str(),arquivo);
} 