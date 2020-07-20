#include <iostream>
#include <string>

#include "Funcionario.h"

using namespace std;

class Seguranca: public Funcionario
{
private:
	char turno;
public:
	static int quantidadeSegurancas;

	Seguranca(string nome, int estreia);
	//~Seguranca();

	char retornarTurno();
	void alterarTurno(char novoTurno);
};