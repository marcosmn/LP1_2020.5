#include "Data.h"
#include "Diario.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
  std::string dataAux = "25/06/2020 insira uma mensagem";
  Data data;
  
  std::stringstream stream(dataAux);
  
  char barra;
  stream >> data.dia;
  stream >> barra;
  stream >> data.mes;
  stream >> barra;
  stream >> data.ano;
  
  Mensagem mensagemAux;
  mensagemAux.conteudo = "Mensagem";
  
  std::cout << data.dia; << std::endl;
  std::cout << data.mes; << std::endl;
  std::cout << data.ano; << std::endl;

  return 0;
}
