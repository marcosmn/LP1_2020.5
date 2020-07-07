#include "Cliente.h"

using namespace std;

class Conta
{
public:
	Cliente titular;
	int numero;
	double saldo;

	/*
	Conta(Cliente novoTitular);
	Conta();
	~Conta();
	*/

	void sacar(double valor);
	void depositar(double valor);
	void transferir(double valor, Conta &destino);
};