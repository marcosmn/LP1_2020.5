#include "Empresa.h"

using namespace std;

Empresa::Empresa()
{
}
Empresa::~Empresa()
{
}

void Empresa::setNome(string novoNome)
{
	this->nome = novoNome;
}
string Empresa::getNome()
{
	return this->nome;
}

void Empresa::setCnpj(int novoCnpj)
{
	this->cnpj = novoCnpj;
}
int Empresa::getCnpj()
{
	return this->cnpj;
}