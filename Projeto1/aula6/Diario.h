#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Mensagem.h"
#include <string>

struct Diario
{
    Diario(const std::string& filename);

    std::string filename;
    Mensagem* mensagens;
    size_t tamanho_mensagens;
    size_t capacidade_mensagens;

    void add(const std::string& mensagem);
    void write();
};

#endif
