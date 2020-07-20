#include <string>

#include "Cliente.h"

using namespace std;

class ClientePF : public Cliente
{
public:
	static int quantidadeClientesPF;
	string nome;
	int cpf;

	ClientePF();
	//~ClientePF();
};