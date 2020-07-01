#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Mensagem.h"
#include <string>
#include <vector>

struct Diario
{
	Diario(const std::string& filename);
	~Diary();

	std::string filename;
	//Mensagem* mensagens;
	std::vector<Mensagem> mensagens;
	size_t quantidade_mensagens;
	size_t capacidade_mensagens;
	
	void add(const std::string& mensagem);
	void add(const Mensagem& mensagem);
	void write();
	//Mensagem* pesquisar(const std::string& mensagem);
	std::vector<Mensagem*> pesquisar(const std::string& mensagem);
};

#endif
