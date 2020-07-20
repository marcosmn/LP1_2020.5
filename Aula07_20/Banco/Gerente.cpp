#include "Gerente.h"

using namespace std;

Gerente::Gerente(string nome, int estreia) : Funcionario(nome, estreia)
{

}

string Gerente::retornarSetor()
{
	return this->setor;
}
void Gerente::alterarSetor(string novoSetor)
{
	this->setor = novoSetor;
}