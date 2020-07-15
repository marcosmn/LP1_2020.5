#include "Mensagem.h"

#include <sstream>

Data::Data() : ano(0), mes(0), dia(0)
{
}

Data Data::dataAtual()
{
	Data dataAux;
	
	/*
	std::stringstream stream(dataString);
	char barra;
	stream >> dataAux.dia;
	stream >> barra;
	stream >> dataAux.mes;
	stream >> barra;
	stream >> dataAux.ano;
	*/
	
	time_t rawtime;
	//struct tm * timeinfo;
	struct tm * timeinfo;
	time(&rawtime);
	//localtime_s(timeinfo, &rawtime);
	timeinfo = localtime(&rawtime);

	//timeinfo = localtime(&rawtime);

	
	dataAux.ano = timeinfo -> tm_year;
	dataAux.mes = timeinfo -> tm_mon;
	dataAux.dia = timeinfo -> tm_mday;
	dataAux.tempo.hora = timeinfo -> tm_hour;
	dataAux.tempo.minuto = timeinfo -> tm_min;
	dataAux.tempo.segundo = timeinfo -> tm_sec;
	
	/*
	dataAux.ano = timeinfo.tm_year;
	dataAux.mes = timeinfo.tm_mon;
	dataAux.dia = timeinfo.tm_mday;
	dataAux.tempo.hora = timeinfo.tm_hour;
	dataAux.tempo.minuto = timeinfo.tm_min;
	dataAux.tempo.segundo = timeinfo.tm_sec;
	*/
    return dataAux;
}