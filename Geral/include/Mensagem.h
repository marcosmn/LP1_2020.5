#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

struct Tempo
{
	int hora;
  	int minuto;
  	int segundo;
};

struct Data
{
	Tempo tempo;
	int dia;
  	int mes;
  	int ano;
	
	Data();
	Data dataAtual();
};

struct Mensagem
{
	Data data;
	string conteudo;
};
