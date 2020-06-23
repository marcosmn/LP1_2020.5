#include <string>

using namespace std;

struct Hora
{
	int hora;
  	int minuto;
  	int segundo;
};

struct Data
{
	int dia;
  	int mes;
  	int ano;
};

struct Mensagem
{
	Hora hora;
	Data data;
	string mensagem;
};
