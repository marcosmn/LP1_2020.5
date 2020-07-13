#include <string>
#include "Empresa.h"

using namespace std;

class Funcionario
{
public:
	Funcionario();
	~Funcionario();

	void setEmpresa(Empresa novaEmpresa);
	Empresa getEmpresa();
	void setNome(string novoNome);
	string getNome();
	void setSalario(int novoSalario);
	double getSalario();
	void setDataAdmissao(int novaDataAdmissao);
	int getDataAdmissao();
	void setDepartamento(string novoDepartamento);
	string getDepartamento();

private:
	Empresa empresa;
	string nome;
	double salario;
	int dataAdmissao;
	string departamento;
};