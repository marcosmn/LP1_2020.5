#include "Fornecedor.h"

using namespace std;

Fornecedor::Fornecedor()
{
	cout << "Abrindo deposito..." << endl;
	fstream deposito;
	deposito.open("fornecedor.csv");

	if (!deposito.is_open())
	{
		cerr << "Arquivo não existente ou sem permissão de leitura." << endl;
		return;
	}

	string linha;
	getline(deposito, linha);
	
	while (!deposito.eof())
	{
		getline(deposito, linha);
		if (linha.size() == 0)
		{
			continue;
		}

		produtos.push_back(linha);
		//this->produtos.push_back(linha.substr(0, linha.find(",")));
	}

	deposito.close();
}

Fornecedor::~Fornecedor()
{
	cout << "Abrindo deposito..." << endl;
	fstream deposito;
	deposito.open("fornecedor.csv");
	deposito << "PRODUTO,QUANTIDADE" << endl;
	int tamanhoAux = produtos.tamanho();
	tamanhoAux++;
	for (int contador = 0; contador < tamanhoAux; contador++)
	{
		deposito << produtos.back() << endl;
		produtos.pop_back();
	}

	deposito.close();
}

void Fornecedor::listarProdutos()
{
	string* inicioVetor = produtos.inicio();
	int tamanhoAux = produtos.tamanho();
	tamanhoAux++;
	for (int contador = 0; contador < tamanhoAux; contador++)
	{
		cout << *inicioVetor << endl;
		++inicioVetor;
	}
	cout << *inicioVetor << endl;
}

bool Fornecedor::repassarProdutos(string nomeProduto, int quantidadeProduto)
{
	size_t posicaoAux;
	int distanciaAux;
	string stringAuxiliar;
	int intAuxiliar;
	int tamanhoAux = produtos.tamanho();
	tamanhoAux++;
	for (int contador = 0; contador < tamanhoAux; contador++)
	{
		posicaoAux = produtos.elementoPosicao(contador).find(",");
		distanciaAux = produtos.elementoPosicao(contador).size() - posicaoAux;
		stringAuxiliar = produtos.elementoPosicao(contador).substr(0, posicaoAux);
		if(stringAuxiliar == nomeProduto)
		{
			posicaoAux++;
			intAuxiliar = stoi(produtos.elementoPosicao(contador).substr(posicaoAux));
			if (intAuxiliar >= quantidadeProduto)
			{
				intAuxiliar = intAuxiliar - quantidadeProduto;
				stringAuxiliar = to_string(intAuxiliar);
				produtos.alterar(contador)->replace(posicaoAux, distanciaAux, stringAuxiliar);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}