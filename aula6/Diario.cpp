#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn)
{
}

void Diario::add(const std::string& mensagem)
{
    capacidade_mensagens++;
    diario.mensagens[capacidade_mensagens] = mensagem;
}

void Diario::write()
{
}
