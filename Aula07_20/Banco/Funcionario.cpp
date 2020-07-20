#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario(string nome, int estreia)
{
	this->nome = nome;
	this->estreia = estreia;
}

string Funcionario::retornarNome()
{
	return this->nome;
}
int Funcionario::retornarEstreia()
{
	return this->estreia;
}
double Funcionario::retornarSalario()
{
	return this->salario;
}

void Funcionario::alterarSalario(int novoSalario)
{
	this->salario = novoSalario;
}