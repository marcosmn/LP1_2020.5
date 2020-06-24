#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn), capacidade_mensagens(10), mensagens(nullptr)
{
  tamanho_mensagens = 0;
  mensagens = new Mensagem[capacidade_mensagens];
}

Diario::~Diario()
{
  delete[] messages;
}

void Diario::add(const std::string& mensagem)
{
  if(tamanho_mensagens < capacidade_mensagens)
  {
    //diario.mensagens[tamanho_mensagens] = mensagem;
    mensagens[tamanho_mensagens].conteudo = mensagem;

    tamanho_mensagens++;
  }
}

void Diario::write()
{
}
