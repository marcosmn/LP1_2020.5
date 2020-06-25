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
  stream >> data.barra;
  stream >> data.mes;
  stream >> data.barra;
  stream >> data.ano;

  return 0;
}
