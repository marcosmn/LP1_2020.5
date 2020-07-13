#include "Estabelecimento.h"

using namespace std;

Estabelecimento::Estabelecimento()
{
	//estoque.open("estoque.csv");

	cout << "Abrindo estoque..." << endl;
	arquivo.open("estoque.csv");

	if (!arquivo.is_open())
	{
		cerr << "Arquivo não existente ou sem permissão de leitura." << endl;
		return;
	}

	string linha;
	getline(arquivo, linha);
	//cout << linha << endl;

	size_t posicao = 0;
	size_t tamanho = 0;

	int codigoAux;
	string produtoAux;
	string unidadeMedidaAux;
	double precoAux;
	int quantidadeAux;
	while (!arquivo.eof())
	{
		getline(arquivo, linha);
		if (linha.size() == 0)
		{
			continue;
		}

		posicao = 0;
		// Codigo
		tamanho = linha.find(",", posicao);
		codigoAux = stoi(linha.substr(posicao, tamanho));
		codigo[totalItens] = codigoAux;
		// Produto
		posicao = tamanho + 1;
		tamanho = linha.find(",", posicao);
		produtoAux = linha.substr(posicao, (tamanho - posicao));
		produto[totalItens] = produtoAux;
		// Medida
		posicao = tamanho + 1;
		tamanho = linha.find(",", posicao);
		unidadeMedidaAux = linha.substr(posicao, (tamanho - posicao));
		unidadeMedida[totalItens] = unidadeMedidaAux;
		// Preço
		posicao = tamanho + 1;
		tamanho = linha.find(",", posicao);
		precoAux = stod(linha.substr(posicao, (tamanho - posicao)));
		preco[totalItens] = precoAux;
		// Quantidade
		posicao = tamanho + 1;
		tamanho = linha.find(",", posicao);
		quantidadeAux = stoi(linha.substr(posicao, (tamanho - posicao)));
		quantidade[totalItens] = quantidadeAux;

		totalItens++;
	}

	arquivo.close();
}

Estabelecimento::~Estabelecimento()
{
	arquivo.open("estoque.csv");

	arquivo << "COD,PRODUTO,UNIDADE_DE_MEDIDA,PREÇO,QUANTIDADE" << endl;
	for(size_t contador = 0; contador < totalItens; contador++)
	{
		arquivo << codigo[contador] << "," << produto[contador] << "," << unidadeMedida[contador] << "," << preco[contador] << "," << quantidade[contador] << endl;
	}

	arquivo.close();

	arquivo.open("caixa.csv");

	arquivo << "CODIGO,NOME,PREÇO,QUANTIDADE_VENDIDA" << endl;
	for (size_t contador = 0; contador < totalItens; contador++)
	{
		arquivo << codigo[contador] << "," << produto[contador] << "," << preco[contador] << "," << vendas[contador] << endl;
	}
	arquivo << "Vendas totais: " << vendasTotais << " (R$ " << vendasLucro << ")" << endl;

	arquivo.close();
}

void Estabelecimento::listar()
{
	for(size_t contador = 0; contador < totalItens; contador++)
	{
		cout << codigo[contador] << " - " << produto[contador] << "(" << unidadeMedida[contador] << ") - R$ " << preco[contador] << " - [" << quantidade[contador] << "]" << endl;
	}

	/*
	cout << "Abrindo estoque..." << endl;
	arquivo.open("estoque.csv");

	if (!arquivo.is_open())
	{
		cerr << "Arquivo não existente ou sem permissão de leitura." << endl;
	}

	string linha;
	getline(arquivo, linha);
	cout << linha << endl;

	size_t posicao = 0;
	size_t tamanho = 0;
	while(!arquivo.eof())
	{
		getline(arquivo, linha);
		if(linha.size() == 0)
		{
			continue;
		}

		posicao = 0;
		// ID
		tamanho = linha.find(",", posicao);
		cout << linha.substr(posicao, tamanho) << " - ";
		// Produto
		posicao = tamanho+1;
		tamanho = linha.find(",", posicao);
		cout << linha.substr(posicao, (tamanho-posicao)) << "(";
		// Medida
		posicao = tamanho+1;
		tamanho = linha.find(",", posicao);
		cout << linha.substr(posicao, (tamanho-posicao)) << ") - ";
		// Preço
		posicao = tamanho+1;
		tamanho = linha.find(",", posicao);
		cout << linha.substr(posicao, (tamanho-posicao)) << " - [";
		// Quantidade
		posicao = tamanho+1;
		tamanho = linha.find(",", posicao);
		cout << linha.substr(posicao, (tamanho-posicao)) << "] \n";
	}

	arquivo.close();
	*/
}

void Estabelecimento::venda(Cliente* cliente, int codigoAux)
{
	for(size_t contador = 0; contador < totalItens; contador++)
	{
		if(codigo[contador] == codigoAux)
		{
			if (quantidade[contador] > 0)
			{
				cout << "Produto está no estoque... \n";

				if(cliente->compra(produto[contador], preco[contador]))
				{
					vendas[contador]++;
					vendasTotais++;
					vendasLucro += preco[contador];
					quantidade[contador]--;
				}
			}
			else
			{
				cout << "Produto não está no estoque... \n";
			}
		}
	}

	/*
	arquivo.open("estoque.csv");

	string linha;

	for(size_t posicao = 0; posicao < codigoAux; posicao++)
	{
		getline(arquivo, linha);
	}

	getline(arquivo, linha);
	int quantidadeAux;
	
	size_t lugar = 0;
	size_t tamanho = linha.find(",", lugar);
	cout << linha.substr(lugar, tamanho) << " - ";
	for (int virgula = 0; virgula < 4; virgula++)
	{
		lugar = tamanho + 1;
		tamanho = linha.find(",", lugar);
	}

	quantidadeAux = stoi(linha.substr(lugar, (tamanho - lugar)));
	cout << quantidadeAux;

	if (quantidadeAux > 0)
	{
		cout << "Produto está no estoque... \n";

		quantidadeAux--;
	}
	else
	{
		cout << "Produto não está no estoque... \n";
	}

	arquivo.close();
	*/
}

void Estabelecimento::caixa()
{
	arquivo.open("caixa.csv");
	string linha;
	getline(arquivo, linha);

	for (size_t contador = 0; contador < totalItens; contador++)
	{
		if(vendas[contador] > 0)
		{
			cout << codigo[contador] << " - " << produto[contador] << "(R$ " << preco[contador] << ") - " << vendas[contador] << endl;
		}
	}

	cout << "Vendas totais: " << vendasTotais << " (R$ " << vendasLucro << ")" << endl;

	arquivo.close();
}