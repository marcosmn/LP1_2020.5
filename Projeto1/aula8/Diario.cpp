#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn), capacidade_mensagens(10), mensagens(nullptr)
{
  tamanho_mensagens = 0;
  mensagens = new Mensagem[capacidade_mensagens];
}

Diario::~Diario()
{
  delete[] mensagens;
}

void Diario::add(const std::string& mensagem)
{
  if(tamanho_mensagens < capacidade_mensagens)
  {
    //diario.mensagens[tamanho_mensagens] = mensagem;
    //mensagens[tamanho_mensagens].conteudo = mensagem;
    
    Mensagem mensagemAux;
    mensagemAux.conteudo = mensagem;
    Data dataAux;
    dataAux.set_from_string(dataAtual());
    mensagemAux.data = dataAux;
    Hora horaAux;
    horaAux.set_from_string(horaAtual());
    mensagemAux.hora = horaAux;
    
    mensagens[tamanho_mensagens] = mensagemAux;

    tamanho_mensagens++;
  }
}

void Diario::write()
{
}
