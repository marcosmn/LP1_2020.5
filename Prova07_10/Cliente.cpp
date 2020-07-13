#include "Cliente.h"

using namespace std;

int Cliente::quantidadeClientes;

Cliente::Cliente(double saldoAux)
{
	saldo = saldoAux;
	this->quantidadeClientes += 1;
}

bool Cliente::compra(string produtoAux, double precoAux)
{
	if(saldo >= precoAux)
	{
		saldo = saldo - precoAux;

		produtoAux = produtoAux + " (" + to_string(precoAux) + ")";
		sacola.push_back(produtoAux);

		return true;
	}
	else
	{
		cout << "Não tem saldo suficiente" << endl;

		return false;
	}
}

void Cliente::verSacola()
{
	for(size_t posicao = 0; posicao < sacola.size(); posicao++)
	{
		cout << sacola[posicao] << endl;
	}
}

void Cliente::registro()
{
	string nomeArquivo = "cliente_";
	nomeArquivo.append(to_string(this->quantidadeClientes));
	nomeArquivo.append(".txt");

	ofstream registroCliente;
	registroCliente.open(nomeArquivo);
	for (size_t posicao = 0; posicao < sacola.size(); posicao++)
	{
		registroCliente << sacola[posicao] << "\n";
	}

	registroCliente.close();
}