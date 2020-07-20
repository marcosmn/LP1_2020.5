#include <iostream>
#include <string>

#include "Funcionario.h"

using namespace std;

class Gerente: public Funcionario
{
private:
	string setor;
public:
	static int quantidadeGerentes;

	Gerente(string nome, int estreia);
	//~Gerente();

	string retornarSetor();
	void alterarSetor(string novoSetor);
};