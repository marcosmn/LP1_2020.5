#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diario.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>

struct App
{
	App(const std::string& filename);
	~App();
	
	Diario diario;
	std::string formato;
	//std::ifstream arquivoConfiguracao;
	
    int run(int argc, char* argv[]);
    void add();
    void add(const std::string mensagem);
	void buscar();
	void buscar(const std::string mensagem);
	void listar();
	void listar(const std::string formatoInformado);
	void listarMensagem(const std::size_t numeroMensagem, const std::string formatoInformado);
	void menu();
	int show_usage();
};

#endif