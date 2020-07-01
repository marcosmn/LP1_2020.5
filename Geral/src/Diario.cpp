#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn), capacidade_mensagens(10), mensagens(nullptr)
{
	quantidade_mensagens = 0;
	mensagens = new Mensagem[capacidade_mensagens];
	
	std::ifstream arquivo;
	arquivo.open(filename);
	if (arquivo.is_open())
	{
		std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
		return 1;
	}
	
	std::string linha;
	while (arquivo.eof())
	{
		std::getline(arquivo, linha);
		if (linha.size() == 0) {
			continue;
		}
		
		//diario.add(linha);
		add(linha);
	}

	arquivo.close();
}

Diario::~Diario()
{
	delete[] mensagens;
}

void Diario::add(const std::string& mensagem)
{
	Mensagem mensagemAux;
	mensagemAux.conteudo = mensagem;
	
	Data dataAux;
	dataAux.set_from_string(dataAtual());
	mensagemAux.data = dataAux;
	
	Hora horaAux;
	horaAux.set_from_string(horaAtual());
	mensagemAux.hora = horaAux;
	
	//mensagens[quantidade_mensagens] = mensagemAux;
	//diario.add(mensagemAux);
	mensagens.push_back(mensagemAux);
	quantidade_mensagens++;
	
	// O VECTOR CUIDA DA CAPACIDADE
	/*
	if(quantidade_mensagens < capacidade_mensagens)
	{
		//diario.mensagens[quantidade_mensagens] = mensagem;
		//mensagens[quantidade_mensagens].conteudo = mensagem;
		
		Mensagem mensagemAux;
		mensagemAux.conteudo = mensagem;
		
		Data dataAux;
		dataAux.set_from_string(dataAtual());
		mensagemAux.data = dataAux;
		
		Hora horaAux;
		horaAux.set_from_string(horaAtual());
		mensagemAux.hora = horaAux;
		
		//mensagens[quantidade_mensagens] = mensagemAux;
		//diario.add(mensagemAux);
		add(mensagemAux);
		
		quantidade_mensagens++;
	}
	else
	{
		std::cout << "Abrindo mais 10 vagas" << std::endl;
		
		mensagensAux = new Mensagem[capacidade_mensagens];
		
		for(int contador = 0; contador < capacidade_mensagens; contador++)
		{
			mensagensAux[contador] = mensagens[contador];
		}
		
		delete[] mensagens;
		mensagens = new Mensagem[capacidade_mensagens + 10];
		
		for(int contador = 0; contador < capacidade_mensagens; contador++)
		{
			mensagens[contador] = mensagensAux[contador];
		}
	  
		capacidade_mensagens = capacidade_mensagens + 10;
	}
	*/
}

void Diario::add(const Mensagem& mensagem)
{
	//mensagens[quantidade_mensagens] = mensagem;
	mensagens.push_back(mensagem);
}

void Diario::write()
{
}

//Mensagem* Diario::pesquisar(const std::string& mensagem)
std::vector<Mensagem*> Diario::pesquisar(const std::string& mensagem)
{
	std::vector<Mensagem*> mensagensCorrespondentes;
	for(int posicao = 0; posicao < quantidade_mensagens; posicao++)
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
