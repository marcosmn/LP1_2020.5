#include "Conta.h"

using namespace std;

int Conta::quantidadeContas;

Conta::Conta()
{
	this->quantidadeContas += 1;
}

void Conta::sacar(double valor)
{
	saldo = saldo - valor;
}

void Conta::depositar(double valor)
{
	saldo = saldo + valor;
}

void Conta::transferir(double valor, Conta &destino)
{
	destino.saldo += valor;
}