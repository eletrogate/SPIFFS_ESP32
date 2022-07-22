/**
  Escreve o conteúdo informado em um novo arquivo da SPIFFS

  @param path : o caminho/nome do novo arquivo à ser escrito
  @param message : o conteúdo do arquivo que será gravado
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
bool writeFile(String path, String message) {
  Serial.print("Gravando o arquivo ");
  Serial.print(path);
  Serial.println(" : ");

  File file = SPIFFS.open(path, FILE_WRITE); // Abre o arquivo, no modo escrita,
  //                                              onde será gravado o seu conteúdo
  //                                              e passa o retorno para
  //                                              uma variável do tipo File.
  if (!file) // Se houver falha ao abrir o caminho, ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir arquivo para gravação");
    return false;
  }
  if (file.print(message)) // Se a escrita do arquivo com seu conteúdo der certo, ...
  {
    // informa ao usuário que deu certo
    Serial.println(" - arquivo escrito");
  } else {
    // informa ao usuário que deu erros e sai da função retornando false.
    Serial.println(" - falha na gravação do arquivo");
    return false;
  }
  file.close(); // Fecha o arquivo
  return true; // retorna true se não houver nenhum erro
}
