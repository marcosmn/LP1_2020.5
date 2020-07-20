#include <iostream>
#include "Conta.h"
#include "Agencia.h"
#include "ClientePJ.h"
#include "ClientePF.h"
#include "Fila.h"
#include "Caixa.h"
#include "Seguranca.h"
#include "Gerente.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

	// Declarando cliente pessoa fisica
	ClientePF clientepf1;
	clientepf1.nome = "Pedro";
	clientepf1.cpf = 12345678911;
	ClientePF clientepf2;
	clientepf2.nome = "Jose";
	clientepf2.cpf = 98765432122;

	// Declarando cliente pessoa juridica
	ClientePJ clientepj1;
	clientepj1.setRazaoSocial("Alberto");
	clientepj1.setCnpj(123456789);
	ClientePJ clientepj2;
	clientepj2.setRazaoSocial("Betina");
	clientepj2.setCnpj(987654321);
	ClientePJ clientepj3;
	clientepj3.setRazaoSocial("Carlos");
	clientepj3.setCnpj(432198765);

	// Declarando agencia
	Agencia agencia1;
	agencia1.nome = "Banco do Brasil";
	agencia1.numero = 123;

	// Declarando conta
	Conta conta1;
	conta1.titular = clientepf1;
	conta1.agencia = agencia1;
	conta1.numero = 12345;
	conta1.saldo = 800.00;
	Conta conta2;
	conta2.titular = clientepf2;
	conta2.agencia = agencia1;
	conta2.numero = 54321;
	conta2.saldo = 500.00;

	// Testando operações
	conta1.transferir(100, conta2);
	conta1.sacar(400);
	conta1.depositar(200);
	conta2.depositar(500);

	// Verificando resultados
	cout << "Quantidade clientes pessoa fisica: ";
	cout << clientepf1.quantidadeClientesPF << endl;
	cout << "Quantidade clientes pessoa juridica: ";
	cout << clientepj1.quantidadeClientesPJ << endl;
	cout << "Quantidade contas: ";
	cout << conta1.quantidadeContas << endl;
	cout << "Quantidade clientes totais: ";
	cout << clientepf1.quantidade() << endl;

	Fila<ClientePF> fila(5);
	Fila<ClientePJ> filaPj(3);

	fila.push(clientepf1);
	fila.push(clientepf2);
	filaPj.push(clientepj1);
	filaPj.push(clientepj2);
	filaPj.push(clientepj3);
	
	// Verificando funcionamento da fila
	cout << fila.back().nome << endl;
	cout << filaPj.back().getRazaoSocial() << endl;

	cout << "=========================================================" << endl;
	// Testando funcionarios
	Caixa caixa1("Guiche Primario", 2010);
	caixa1.alterarSalario(5000);
	Caixa caixa2("Guiche Secundario", 2013);
	caixa2.alterarSalario(4000);
	Seguranca seguranca1("Guarda da Manhã", 2010);
	seguranca1.alterarSalario(2000);
	Seguranca seguranca2("Guarda da Tarde", 2010);
	seguranca2.alterarSalario(2000);
	Seguranca seguranca3("Guarda da Noite", 2015);
	seguranca3.alterarSalario(3000);
	Gerente gerente1("Gerente geral", 2010);
	gerente1.alterarSalario(7000);

	cout << caixa1.retornarNome() << " - R$";
	cout << caixa1.retornarSalario() << endl;
	cout << seguranca1.retornarNome() << " - R$";
	cout << seguranca1.retornarSalario() << endl;
	cout << gerente1.retornarNome() << " - R$";
	cout << gerente1.retornarSalario() << endl;

	caixa1.alterarBancada(1);
	seguranca1.alterarTurno('M');
	gerente1.alterarSetor("geral");

	cout << caixa1.retornarBancada() << endl;
	cout << seguranca1.retornarTurno() << endl;
	cout << gerente1.retornarSetor() << endl;

	return 0;
}