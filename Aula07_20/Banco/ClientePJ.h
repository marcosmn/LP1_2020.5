#include <string>

#include "Cliente.h"

using namespace std;

class ClientePJ : private Cliente
{
private:
	string razaoSocial;
	int cnpj;

public:
	static int quantidadeClientesPJ;

	string getRazaoSocial();
	void setRazaoSocial(string novaRazaoSocial);
	int getCnpj();
	void setCnpj(int novoCnpj);

	ClientePJ();
	//~ClientePJ();
};