#include <string>

using namespace std;

class Empresa
{
public:
	Empresa();
	~Empresa();

	void setNome(string novoNome);
	string getNome();
	void setCnpj(int novoCnpj);
	int getCnpj();

private:
	string nome;
	int cnpj;
};