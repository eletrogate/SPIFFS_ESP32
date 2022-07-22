/**
  Lê o conteúdo de um arquivo especificado da SPIFFS

  @param path : o caminho/nome do arquivo à ser listado
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
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
  file.close(); // Fecha o arquivo
  return true; // retorna true se não houver nenhum erro
}
