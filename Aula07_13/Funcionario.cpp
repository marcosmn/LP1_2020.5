#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario()
{
}
Funcionario::~Funcionario()
{
}

void Funcionario::setEmpresa(Empresa novaEmpresa)
{
	this->empresa = novaEmpresa;
}
Empresa Funcionario::getEmpresa()
{
	return this->empresa;
}

void Funcionario::setNome(string novoNome)
{
	this->nome = novoNome;
}
string Funcionario::getNome()
{
	return this->nome;
}

void Funcionario::setSalario(int novoSalario)
{
	this->salario = novoSalario;
}
double Funcionario::getSalario()
{
	return this->salario;
}

void Funcionario::setDataAdmissao(int novaDataAdmissao)
{
	this->dataAdmissao = novaDataAdmissao;
}
int Funcionario::getDataAdmissao()
{
	return this->dataAdmissao;
}

void Funcionario::setDepartamento(string novoDepartamento)
{
	this->departamento = novoDepartamento;
}
string Funcionario::getDepartamento()
{
	return this->departamento;
}