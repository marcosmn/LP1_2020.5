#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "vector_supermercado.h"

using namespace std;

class Fornecedor
{
private:
	Vetor<string> produtos;

public:
	Fornecedor();
	~Fornecedor();
	void listarProdutos();
	bool repassarProdutos(string nomeProduto, int quantidadeProduto);
};