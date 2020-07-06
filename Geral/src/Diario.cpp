#include "Diario.h"

//Diario::Diario(const std::string& fn) : filename(fn), capacidade_mensagens(10), mensagens(nullptr)
Diario::Diario(const std::string& fn) : filename(fn)
{
	quantidade_mensagens = 0;
	//mensagens = new Mensagem[capacidade_mensagens];
	
	std::ifstream arquivo;
	arquivo.open(filename);
	if (arquivo.is_open())
	{
		std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
		//return 1;
	}
	
	std::string linha;
	while (arquivo.eof())
	{
		std::getline(arquivo, linha);
		if (linha.size() == 0) {
			continue;
		}
		
		add(linha);
	}

	arquivo.close();
}

Diario::~Diario()
{
	//delete[] mensagens;
}

void Diario::add(const std::string& mensagem)
{
	Mensagem mensagemAux;
	
	if(mensagem[0] == '-')
	{
		dataAux.tempo.hora = std::stoi(mensagem.substr(2, 2));
		dataAux.tempo.minuto = std::stoi(mensagem.substr(5, 2));
		dataAux.tempo.segundo = std::stoi(mensagem.substr(8, 2));
		
		mensagemAux.data = dataAux;
		mensagemAux.conteudo = mensagem.substr(11);
	}
	else if(mensagem[0] == '#')
	{
		dataAux.dia = std::stoi(mensagem.substr(2, 2));
		dataAux.mes = std::stoi(mensagem.substr(5, 2));
		dataAux.ano = std::stoi(mensagem.substr(8, 4));
	}
	else
	{
		//dataAux.dataAtual();
		mensagemAux.data = dataAux.dataAtual();
		mensagemAux.conteudo = mensagem;
	}
	
	//mensagens[quantidade_mensagens] = mensagemAux;
	//add(mensagemAux);
	mensagens.push_back(mensagemAux);
	quantidade_mensagens++;
}

void Diario::add(const Mensagem& mensagem)
{
	//mensagens[quantidade_mensagens] = mensagem;
	mensagens.push_back(mensagem);
	quantidade_mensagens++;
}

void Diario::write()
{
}

//Mensagem* Diario::pesquisar(const std::string& mensagem)
std::vector<Mensagem*> Diario::pesquisar(const std::string& mensagem)
{
	std::vector<Mensagem*> mensagensCorrespondentes;
	for(size_t posicao = 0; posicao < quantidade_mensagens; posicao++)
	{
    	if(mensagens[posicao].conteudo.find(mensagem) != std::string::npos)
		{
      		//return &mensagens[posicao];
			mensagensCorrespondentes.push_back(&mensagens[posicao]);
		}
    }
	
	//return nullptr;
	return mensagensCorrespondentes;
}