#include "App.h"

App::App(const std::string& filename) : diario(filename)
{
	std::ifstream arquivoConfiguracao;
	arquivoConfiguracao.open("diario.config");
	
	std::string linha;
	std::getline(arquivoConfiguracao, linha);
	std::getline(arquivoConfiguracao, linha);
	formato = linha.substr(15); // Corta o inicio "default_format="
	//formato.clear();
	//formato.append(linha.substr(15)); // Corta o inicio "default_format="
	
	arquivoConfiguracao.close();
}

App::~App()
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
	else if (action == "search")
    {
		if (argc == 2)
        {
            buscar();
        }
        else
        {
            buscar(argv[2]);
        }
    }
    else if (action == "list")
    {
		if (argc == 2)
        {
            listar(formato);
        }
        else
        {
            listar(argv[2]);
        }
    }
	else if (action == "interactive")
    {
        menu();
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

void App::buscar()
{
    std::string mensagem;
    std::cout << "Insira sua pesquisa:" << std::endl;
    std::getline(std::cin, mensagem);

    buscar(mensagem);
}

void App::buscar(const std::string mensagem)
{
    std::vector<Mensagem*> mensagensCorrespondentes = diario.pesquisar(mensagem);
}

void App::listar()
{
	const std::string formatoInformado = "[%d %t] %m";
    for (size_t numeroMensagem = 0; numeroMensagem < diario.quantidade_mensagens; ++numeroMensagem)
    {
		listarMensagem(numeroMensagem, formatoInformado);
    }
}

void App::listar(const std::string formatoInformado)
{
	for (size_t numeroMensagem = 0; numeroMensagem < diario.quantidade_mensagens; ++numeroMensagem)
    {
		listarMensagem(numeroMensagem, formatoInformado);
    }
}

void App::listarMensagem(const std::size_t numeroMensagem, const std::string formatoInformado)
{
	const Mensagem& mensagem = diario.mensagens[numeroMensagem];
	
	std::size_t tamanho = formatoInformado.length();
	std::string mensagemFormatada = "";
	char caractere;
	
	std::size_t posicao = 0;
	while(posicao < tamanho)
	{
		if(formatoInformado[posicao] == '%')
		{
			posicao++;
			caractere = formatoInformado[posicao];
			switch(caractere)
			{
				case 'd':
					mensagemFormatada.append(to_string(mensagem.data.dia));
					mensagemFormatada.append("/");
					mensagemFormatada.append(to_string(mensagem.data.mes));
					mensagemFormatada.append("/");
					mensagemFormatada.append(to_string(mensagem.data.ano));
					break;
				case 't':
					mensagemFormatada.append(to_string(mensagem.data.tempo.hora));
					mensagemFormatada.append(":");
					mensagemFormatada.append(to_string(mensagem.data.tempo.minuto));
					mensagemFormatada.append(":");
					mensagemFormatada.append(to_string(mensagem.data.tempo.segundo));
					break;
				case 'm':
					mensagemFormatada.append(mensagem.conteudo);
					break;
				default:
					std::cout << "Formato invalido" << std::endl;
					break;
			}
		}
		else
		{
			mensagemFormatada.append(to_string(formatoInformado[posicao]));
		}
		
		posicao++;
	}
	
    std::cout << mensagemFormatada << std::endl;
}

void App::menu()
{
	int comando = 5;
	while(comando != 0)
	{
		std::cout << "Diario 1.0" << std::endl;
		std::cout << "Selecione uma ação:\n" << std::endl;
		std::cout << "1) Adicionar mensagem" << std::endl;
		std::cout << "2) Buscar mensagem" << std::endl;
		std::cout << "3) Listar mensagens\n" << std::endl;
		std::cout << "0) Finalizar" << std::endl;
		
		std::cin >> comando;
		
		switch(comando)
		{
			case 0:
				break;
			case 1:
				add();
				break;
			case 2:
				buscar();
				break;
			case 3:
				listar();
				break;
			default:
				std::cout << "Comando invalido" << std::endl;
				break;
		}
	}
}

int App::show_usage()
{
    return 1;
}
