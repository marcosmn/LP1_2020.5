#include <iostream>
#include "Empresa.h"
#include "Funcionario.h"

using namespace std;

int main()
{
    cout << "Criando uma empresa...\n";
	Empresa empresa;
	empresa.setNome("McDonalds");
	empresa.setCnpj(123456);

	int quantidadeFuncionarios;
	cout << "Quantos funcionarios tera essa empresa? ";
	cin >> quantidadeFuncionarios;
	cout << "\nContatando os funcionarios...\n";
	Funcionario* funcionario = new Funcionario[quantidadeFuncionarios];

	string novoNome;
	double novoSalario;
	int novaDataAdmissao;
	string novoDepartamento;
	for(int contador = 0; contador < quantidadeFuncionarios; contador++)
	{
		cout << "Contratando um funcionario...\n";
		funcionario[contador].setEmpresa(empresa);

		cout << "Informe o nome: ";
		cin >> novoNome;
		cout << "Informe o salario: ";
		cin >> novoSalario;
		cout << "Informe a data de admissao: ";
		cin >> novaDataAdmissao;
		cout << "Informe o departamento: ";
		cin >> novoDepartamento;

		funcionario[contador].setNome(novoNome);
		funcionario[contador].setSalario(novoSalario);
		funcionario[contador].setDataAdmissao(novaDataAdmissao);
		funcionario[contador].setDepartamento(novoDepartamento);
	}

	string departamentoPrivilegiado;
	cout << "Escolha um departamento para dar um aumento de 10%\n";
	cin >> departamentoPrivilegiado;
	for (int contador = 0; contador < quantidadeFuncionarios; contador++)
	{
		if(funcionario[contador].getDepartamento() == departamentoPrivilegiado)
		{
			novoSalario = funcionario[contador].getSalario() * 1.10;
			funcionario[contador].setSalario(novoSalario);
		}
	}
	cout << "Aumento distribuido...\n";

	cout << "Resultado: \n";
	for (int contador = 0; contador < quantidadeFuncionarios; contador++)
	{
		cout << funcionario[contador].getNome() << " (";
		cout << funcionario[contador].getDepartamento() << ") - ";
		cout << funcionario[contador].getSalario() << endl;
	}

	return 0;
}