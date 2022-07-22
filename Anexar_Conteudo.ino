/**
  Adiciona conteúdo informado em um arquivo existente da SPIFFS

  @param path : o caminho/nome do arquivo à ser escrito
  @param message : o conteúdo do arquivo que será anexado
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
bool appendFile(String path, String message) {
  Serial.print("Anexando conteúdo ao arquivo ");
  Serial.print(path);
  Serial.println(" : ");

  File file = SPIFFS.open(path, FILE_APPEND); // Abre o arquivo, no modo anexar,
  //                                              onde será adicionado conteúdo
  //                                              e passa o retorno para
  //                                              uma variável do tipo File.

  if (!file)  // Se houver falha ao abrir o caminho, ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir o arquivo para anexar");
    return false;
  }

  if (file.print(message)) // Se a escrita do arquivo com seu conteúdo der certo, ...
  {
    // informa ao usuário que deu certo
    Serial.println(" - mensagem anexada");
  } else {
    // informa ao usuário que deu erros e sai da função retornando false.
    Serial.println(" - Falha ao anexar");
    return false;
  }

  file.close(); // Fecha o arquivo
  return true; // retorna true se não houver nenhum erro
}
