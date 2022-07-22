/**
  Renomeia um determinado arquivo existente da SPIFFS

  @param path1 : o caminho/nome do arquivo à ser renomeado
  @param path2 : o novo caminho/nome do arquivo
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
bool renameFile(String path1, String path2) {
  Serial.print("Renomenando arquivo ");
  Serial.print(path1);
  Serial.print(" para ");
  Serial.print(path2);
  Serial.println(" : ");

  if (SPIFFS.rename(path1, path2)) // renomeia o arquivo passando o
    //                                  antigo caminho/nome (path1) e o
    //                                  novo caminho/nome (path2)
    //                                Se a renomeação der certo, ...
  {
    // informa ao usuário que deu certo
    Serial.println(" - arquivo renomeado");
  } else {
    // informa ao usuário que deu erros e sai da função retornando false.
    Serial.println(" - falha ao renomear");
    return false;
  }
  return true; // retorna true se não houver nenhum erro
}
