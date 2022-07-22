/******************************************************************************
                  SPIFFS: Armazenamento de Arquivos do ESP32
                           Sketch de Teste da SPIFFS

                            Criado em 19 mar. 2022
                              por Michel Galvão

  Eletrogate - Loja de Arduino \\ Robótica \\ Automação \\ Apostilas \\ Kits
                            https://www.eletrogate.com/
******************************************************************************/

// Inclusão da(s) biblioteca(s)
#include "SPIFFS.h"
#include "FS.h"

// Protótipo das Funções
bool listDir();
bool readFile(String path);

void setup() {
  Serial.begin(115200);
  Serial.println();
  SPIFFS.begin();
  listDir();
  Serial.println();
  readFile("/arquivoTRANSFERIDO_1.txt");
  Serial.println();
  readFile("/arquivoTRANSFERIDO_2.txt");  
}

void loop() {}

bool listDir() {
  File root = SPIFFS.open("/"); // Abre o "diretório" onde estão os arquivos na SPIFFS
  //                                e passa o retorno para
  //                                uma variável do tipo File.
  if (!root) // Se houver falha ao abrir o "diretório", ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir o diretório");
    return false;
  }

  File file = root.openNextFile(); // Relata o próximo arquivo do "diretório" e
  //                                    passa o retorno para a variável
  //                                    do tipo File.
  int qtdFiles = 0; // variável que armazena a quantidade de arquivos que
  //                    há no diretório informado.
  while (file) { // Enquanto houver arquivos no "diretório" que não foram vistos,
    //                executa o laço de repetição.
    Serial.print("  FILE : ");
    Serial.print(file.name()); // Imprime o nome do arquivo
    Serial.print("\tSIZE : ");
    Serial.println(file.size()); // Imprime o tamanho do arquivo
    qtdFiles++; // Incrementa a variável de quantidade de arquivos
    file = root.openNextFile(); // Relata o próximo arquivo do diretório e
    //                              passa o retorno para a variável
    //                              do tipo File.
  }
  if (qtdFiles == 0)  // Se após a visualização de todos os arquivos do diretório
    //                      não houver algum arquivo, ...
  {
    // Avisa o usuário que não houve nenhum arquivo para ler e retorna false.
    Serial.print(" - Sem arquivos para ler. Crie novos arquivos pelo menu ");
    Serial.println("principal, opção 2.");
    return false;
  }

  return true; // retorna true se não houver nenhum erro
}

bool readFile(String path) {
  File file = SPIFFS.open(path); // Abre o caminho do arquivo da SPIFFS no
  //                                  e passa o retorno para uma variável do
  //                                  tipo File.
  if (!file)  // Se houver falha ao abrir o caminho, ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir arquivo para leitura");
    return false;
  }

  while (file.available()) // Enquanto houver algum byte disponível para
    //                          leitura do arquivo, executa o bloco de repetição.
  {
    Serial.write(file.read()); // Escreve na Serial os bytes obtidos da leitura
    //                              do arquivo.
  }
  Serial.println();
  file.close(); // Fecha o arquivo
  return true; // retorna true se não houver nenhum erro
}
