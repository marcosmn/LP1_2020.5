#include "Seguranca.h"

using namespace std;

Seguranca::Seguranca(string nome, int estreia) : Funcionario(nome, estreia)
{

}

char Seguranca::retornarTurno()
{
	return this->turno;
}
void Seguranca::alterarTurno(char novoTurno)
{
	this->turno = novoTurno;
}