#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn)
{
  capacidade_mensagens = 10;
  tamanho_mensagens = 0;
  Mensagem *mensagens = new Mensagem[capacidade_mensagens];
}

void Diario::add(const std::string& mensagem)
{
    capacidade_mensagens++;
    diario.mensagens[capacidade_mensagens] = mensagem;
}

void Diario::write()
{
}
