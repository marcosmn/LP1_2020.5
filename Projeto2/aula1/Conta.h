#include "Cliente.h"
#include "Agencia.h"

using namespace std;

class Conta
{
public:
	Cliente titular;
	Agencia agencia;
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