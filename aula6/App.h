#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diario.h"
#include <string>

struct App
{
  App(const std::string& filename);
  Diario diario;
  
  int run(int argc, char* argv[]);
};

#endif
