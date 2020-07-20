#include "Caixa.h"

using namespace std;

Caixa::Caixa(string nome, int estreia) : Funcionario(nome, estreia)
{
	
}

int Caixa::retornarBancada()
{
	return this->bancada;
}
void Caixa::alterarBancada(int novaBancada)
{
	this->bancada = novaBancada;
}