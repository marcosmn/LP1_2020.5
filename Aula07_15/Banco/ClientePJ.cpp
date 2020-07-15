#include "ClientePJ.h"

using namespace std;

int ClientePJ::quantidadeClientesPJ;

ClientePJ::ClientePJ()
{
	this->quantidadeClientesPJ += 1;
}

string ClientePJ::getRazaoSocial()
{
	return razaoSocial;
}
void ClientePJ::setRazaoSocial(string novaRazaoSocial)
{
	this->razaoSocial = novaRazaoSocial;
}

int ClientePJ::getCnpj()
{
	return cnpj;
}
void ClientePJ::setCnpj(int novoCnpj)
{
	this->cnpj = novoCnpj;
}