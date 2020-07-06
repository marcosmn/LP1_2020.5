#include <iostream>
#include "Conta.h"
#include "Cliente.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

	Cliente cliente1;
	cliente1.cpf = 123456;
	Cliente cliente2;
	cliente2.cpf = 654321;

	Conta conta1;
	conta1.titular = cliente1;
	conta1.numero = 123;
	conta1.saldo = 800.00;

	Conta conta2;
	conta2.titular = cliente2;
	conta2.numero = 321;
	conta2.saldo = 500.00;

	conta1.transferir(100, conta2);
	conta1.sacar(400);
	conta1.depositar(200);

	conta2.depositar(500);

	cout << "Saldo conta1: ";
	cout << conta1.saldo << endl;
	cout << "Saldo conta2: ";
	cout << conta2.saldo << endl;

	return 0;
}