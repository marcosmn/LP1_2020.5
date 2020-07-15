#include "Cliente.h"

using namespace std;

int Cliente::quantidadeClientes;

Cliente::Cliente()
{
	this->quantidadeClientes += 1;
}