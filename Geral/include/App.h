#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diario.h"
#include <string>
#include <iostream>
#include <vector>

struct App
{
	Diario diario;
	
    App(const std::string& filename);
	
    int run(int argc, char* argv[]);
    void add();
    void add(const std::string mensagem);
	void buscar(const std::string mensagem);
	void listar();
	int show_usage();
};

#endif
