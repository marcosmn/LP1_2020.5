#include <iostream>
#include <string>

#include "Funcionario.h"

using namespace std;

class Caixa: public Funcionario
{
private:
	int bancada;
public:
	static int quantidadeCaixas;

	Caixa(string nome, int estreia);
	//~Caixa();

	int retornarBancada();
	void alterarBancada(int novaBancada);
};