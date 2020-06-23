#include "Diario.h"

Diario::Diario(const std::string& fn) : filename(fn)
{
}

void Diario::add(const std::string& mensagem)
{
    capacidade_mensagens++;
}

void Diario::write()
{
    for (size_t i = 0; i < diario.tamanho_mensagens; ++i) {
        diario.mensagens[i] = mensagem;
    }
}
