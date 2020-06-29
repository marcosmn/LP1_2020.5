#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diario.h"
#include <string>

struct App
{
	Diario diario;
	
    App(const std::string& filename);
	
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string mensagem);
	void listar();
};

#endif
