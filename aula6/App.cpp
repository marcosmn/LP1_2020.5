#include "App.h"
#include <iostream>
#include <string>

App::App(const std::string& filename) : diario(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1)
    {
        return show_usage();
    }
    
    std::string action = argv[1];
    if (action == "add")
    {
        if (argc == 2)
        {
            add();
        }
        else
        {
            add(argv[2]);
        }
    }
    else if (action == "list")
    {
        listar();
    }
    else if (action == "search")
    {
    }
    else
    {
        return show_usage();
    }
    
    return 0;
}

void App::add()
{
    std::string mensagem;
    std::cout << "Insira sua mensagem:" << std::endl;
    std::getline(std::cin, mensagem);

    add(mensagem);
}

void App::add(const std::string mensagem)
{
    diario.add(mensagem);
    diario.write();
}

void App::listar()
{
    for (size_t i = 0; i < diario.tamanhoMensagens; ++i) {
        const Mensagem& mensagem = diario.mensagens[i];
        std::cout << "-" << mensagem.content << std::endl;
    }
}
