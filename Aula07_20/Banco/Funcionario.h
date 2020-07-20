#include <iostream>
#include <string>

using namespace std;

class Funcionario
{
private:
	string nome;
	int estreia;
	double salario;
public:
	static int quantidadeFuncionarios;

	Funcionario(string nome, int estreia);
	//~Funcionario();

	string retornarNome();
	int retornarEstreia();
	double retornarSalario();

	void alterarSalario(int novoSalario);
};