#include <iostream>
#include "Conta.h"
#include "Cliente.h"
#include "Agencia.h"
#include "ClientePJ.h"
#include "Fila.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

	Cliente cliente1;
	cliente1.nome = "Pedro";
	cliente1.cpf = 12345678911;
	Cliente cliente2;
	cliente2.nome = "Jose";
	cliente2.cpf = 98765432122;

	Agencia agencia1;
	agencia1.nome = "Banco do Brasil";
	agencia1.numero = 123;

	Conta conta1;
	conta1.titular = cliente1;
	conta1.agencia = agencia1;
	conta1.numero = 12345;
	conta1.saldo = 800.00;
	Conta conta2;
	conta2.titular = cliente2;
	conta2.agencia = agencia1;
	conta2.numero = 54321;
	conta2.saldo = 500.00;

	conta1.transferir(100, conta2);
	conta1.sacar(400);
	conta1.depositar(200);

	conta2.depositar(500);

	cout << "Saldo conta1: ";
	cout << conta1.saldo << endl;
	cout << "Saldo conta2: ";
	cout << conta2.saldo << endl;
	cout << "Quantidade contas: ";
	cout << conta1.quantidadeContas << endl;
	
	ClientePJ clientepj1;
	clientepj1.setRazaoSocial("Alberto");
	clientepj1.setCnpj(123456789);
	ClientePJ clientepj2;
	clientepj2.setRazaoSocial("Betina");
	clientepj2.setCnpj(987654321);
	ClientePJ clientepj3;
	clientepj3.setRazaoSocial("Carlos");
	clientepj3.setCnpj(432198765);

	Fila<Cliente> fila(5);
	Fila<ClientePJ> filaPj(3);

	fila.push(cliente1);
	fila.push(cliente2);
	filaPj.push(clientepj1);
	filaPj.push(clientepj2);
	filaPj.push(clientepj3);
	
	cout << fila.back().nome << endl;
	cout << filaPj.back().getRazaoSocial() << endl;

	return 0;
}