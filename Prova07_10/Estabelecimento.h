#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "Cliente.h"

using namespace std;

class Estabelecimento
{
public:
	Estabelecimento();
	~Estabelecimento();

	fstream arquivo;
	size_t totalItens = 0;

	int codigo[100];
	string produto[100];
	string unidadeMedida[100];
	double preco[100];
	int quantidade[100];

	int vendas[100];
	double vendasLucro = 0.0;
	int vendasTotais = 0;

	void listar();
	void venda(Cliente* cliente, int codigoAux);
	void caixa();
};