/**
  Exclui um determinado arquivo existente da SPIFFS

  @param path : o caminho/nome do arquivo à ser excluído
  @return true se ocorreu tudo certo ou false se houve algum erro
*/
bool deleteFile(String path) {
  Serial.print("Deletando arquivo ");
  Serial.print(path);
  Serial.println(" : ");

  if (SPIFFS.remove(path)) // exclui o arquivo passando o
    //                          caminho/nome (path)
    //                        Se a exclusão der certo, ...
  {
    // informa ao usuário que deu certo
    Serial.println(" - arquivo excluído");
  } else {
    // informa ao usuário que deu erros e sai da função retornando false.
    Serial.println(" - falha na exclusão");
    return false;
  }
  return true; // retorna true se não houver nenhum erro
}
