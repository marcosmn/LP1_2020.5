#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "Fornecedor.h"
#include "Cliente.h"
#include "vector_supermercado.h"

using namespace std;

class Estabelecimento
{
public:
	Estabelecimento();
	~Estabelecimento();

	fstream arquivo;
	size_t totalItens = 0;

	Vetor<string> produtos;
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
	void reabastecer(Fornecedor* fornecedor, string nomeProduto, int quantidadeProduto);
};