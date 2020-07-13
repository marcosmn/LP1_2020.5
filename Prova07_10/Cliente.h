#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Cliente
{
public:
	static int quantidadeClientes;
	double saldo;
	std::vector<string> sacola;

	Cliente(double saldoAux);

	bool compra(string produtoAux, double precoAux);
	void verSacola();
	void registro();
};