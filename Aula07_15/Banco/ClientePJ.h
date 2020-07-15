#include <string>

using namespace std;

class ClientePJ
{
private:
	static int quantidadeClientesPJ;
	string razaoSocial;
	int cnpj;
	
public:
	string getRazaoSocial();
	void setRazaoSocial(string novaRazaoSocial);
	int getCnpj();
	void setCnpj(int novoCnpj);

	ClientePJ();
	//~ClientePJ();
};