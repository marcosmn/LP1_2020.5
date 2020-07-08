#include "Cliente.h"
#include "Agencia.h"

using namespace std;

class Conta
{
public:
	static int quantidadeContas;
	Cliente titular;
	Agencia agencia;
	int numero;
	double saldo;
	
	Conta();
	//Conta(Cliente novoTitular, Agencia novaAgencia);
	//~Conta();

	void sacar(double valor);
	void depositar(double valor);
	void transferir(double valor, Conta &destino);
};