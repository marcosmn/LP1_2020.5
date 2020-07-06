#include "App.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::ifstream arquivoConfiguracao;
	arquivoConfiguracao.open("diario.config");

	std::string linha;
	std::getline(arquivoConfiguracao, linha);
	std::string nomeArquivo = linha.substr(5); // Corta o inicio "path="

	arquivoConfiguracao.close();

	//App aplicativo("diario.md");
	App aplicativo(nomeArquivo);
    
    return aplicativo.run(argc, argv);
}
