/**
  Copia um determinado arquivo existente da SPIFFS para outro local

  @param pathOrigem : o caminho/nome do arquivo de origem
  @param pathDestino : o caminho/nome do arquivo de destino
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
bool copyFile(String pathOrigem, String pathDestino) {
  Serial.print("Copiando arquivo ");
  Serial.print(pathOrigem);
  Serial.print(" para ");
  Serial.print(pathDestino);
  Serial.println(" : ");

  File fileOrigem = SPIFFS.open(pathOrigem); // Abre o arquivo do local de origem
  //                                              e passa o retorno para
  //                                              uma variável do tipo File.

  if (!fileOrigem)   // Se houver falha ao abrir o caminho, ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir arquivo para cópia");
    return false;
  }

  File fileDestino = SPIFFS.open(pathDestino, FILE_WRITE); // Abre o arquivo do
  //                                                            local de destino,
  //                                                            no modo escrita,
  //                                                            e passa o retorno para
  //                                                            uma variável do tipo
  //                                                            File.

  if (!fileDestino)   // Se houver falha ao abrir o caminho, ...
  {
    // informa ao usuário que houve falhas e sai da função retornando false.
    Serial.println(" - falha ao abrir arquivo para gravação");
    return false;
  }

  while (fileOrigem.available())  // Enquanto houver algum byte disponível para
    //                                leitura do arquivo, executa o bloco de
    //                                repetição.
  {
    if (!fileDestino.write(fileOrigem.read())) // Se a escrita byte-a-byte do arquivo
      //                                            lido, também byte-a-byte, resultar
      //                                            em algum erro, ...
    {
      // informa ao usuário que deu erros e sai da função retornando false.
      Serial.println(" - falha para mover o arquivo");
      return false;
    }
  }

  //Fecha os arquivos de origem e de destino
  fileOrigem.close();
  fileDestino.close();
  return true; // retorna true se não houver nenhum erro
}
