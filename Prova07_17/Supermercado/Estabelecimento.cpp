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

		this->produtos.push_back(linha);

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
	fstream arquivoCaixa;
	arquivoCaixa.open("caixa.csv");
	//size_t posicaoAux;

	arquivo.open("estoque.csv");
	arquivo << "COD,PRODUTO,UNIDADE_DE_MEDIDA,PREÇO,QUANTIDADE" << endl;
	int tamanhoAux = produtos.tamanho();
	tamanhoAux++;
	for (size_t contador = 0; contador < tamanhoAux; contador++)
	{
		/*
		posicaoAux = produtos.elementoPosicao(contador).find(",");
		posicaoAux = produtos.elementoPosicao(contador).find(",", posicaoAux+1);
		posicaoAux = produtos.elementoPosicao(contador).find(",", posicaoAux+1);
		posicaoAux = produtos.elementoPosicao(contador).find(",", posicaoAux+1);
		arquivoCaixa << produtos.back().substr(0, posicaoAux) << "," << vendas[contador] << endl;
		*/
		//arquivo << produtos.back() << endl;
		arquivo << produtos.elementoPosicao(contador) << endl;
		//cout << produtos.elementoPosicao(contador) << endl; //Teste
		produtos.pop_back();
	}
	/*
	for(size_t contador = 0; contador < totalItens; contador++)
	{
		arquivo << codigo[contador] << "," << produto[contador] << "," << unidadeMedida[contador] << "," << preco[contador] << "," << quantidade[contador] << endl;
	}
	*/
	arquivo.close();

	arquivoCaixa << "CODIGO,NOME,PREÇO,QUANTIDADE_VENDIDA" << endl;
	for (size_t contador = 0; contador < totalItens; contador++)
	{
		arquivoCaixa << codigo[contador] << "," << produto[contador] << "," << preco[contador] << "," << vendas[contador] << endl;
	}
	arquivoCaixa << "Vendas totais: " << vendasTotais << " (R$ " << vendasLucro << ")" << endl;
	arquivoCaixa.close();
}

void Estabelecimento::listar()
{
	string *inicioVetor = this->produtos.inicio();
	int tamanhoAux = produtos.tamanho();
	tamanhoAux++;
	for (int contador = 0; contador < tamanhoAux; contador++)
	{
		//cout << codigo[contador] << " - " << produto[contador] << "(" << unidadeMedida[contador] << ") - R$ " << preco[contador] << " - [" << quantidade[contador] << "]" << endl;
		cout << *inicioVetor << endl;
		++inicioVetor;
	}
	cout << *inicioVetor << endl;
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

					string stringAuxiliar;
					int intAuxiliar;
					size_t posicaoAux;
					int distanciaAux;

					posicaoAux = produtos.elementoPosicao(contador).rfind(",");
					distanciaAux = produtos.elementoPosicao(contador).size() - posicaoAux;
					posicaoAux++;
					intAuxiliar = stoi(produtos.elementoPosicao(contador).substr(posicaoAux));
					intAuxiliar--;
					stringAuxiliar = to_string(intAuxiliar);
					produtos.alterar(contador)->replace(posicaoAux, distanciaAux, stringAuxiliar);
				}
			}
			else
			{
				cout << "Produto não está no estoque... \n";
			}
		}
	}
}

void Estabelecimento::caixa()
{
	for (size_t contador = 0; contador < totalItens; contador++)
	{
		if(vendas[contador] > 0)
		{
			cout << codigo[contador] << " - " << produto[contador] << "(R$ " << preco[contador] << ") - " << vendas[contador] << endl;
		}
	}

	cout << "Vendas totais: " << vendasTotais << " (R$ " << vendasLucro << ")" << endl;
}

void Estabelecimento::reabastecer(Fornecedor* fornecedor, string nomeProduto, int quantidadeProduto)
{
	if(fornecedor->repassarProdutos(nomeProduto, quantidadeProduto))
	{
		string stringAuxiliar;
		int intAuxiliar;
		int posicaoAux;
		int distanciaAux;
		int tamanhoAux = produtos.tamanho();
		tamanhoAux++;
		for (int contador = 0; contador < tamanhoAux; contador++)
		{
			posicaoAux = produtos.elementoPosicao(contador).find(",");
			posicaoAux++;
			distanciaAux = produtos.elementoPosicao(contador).find(",", posicaoAux);
			stringAuxiliar = produtos.elementoPosicao(contador).substr(posicaoAux, (distanciaAux-posicaoAux));
			if (stringAuxiliar == nomeProduto)
			{
				posicaoAux = produtos.elementoPosicao(contador).rfind(",");
				distanciaAux = produtos.elementoPosicao(contador).size() - posicaoAux;
				posicaoAux++;
				intAuxiliar = stoi(produtos.elementoPosicao(contador).substr(posicaoAux));
				intAuxiliar = intAuxiliar + quantidadeProduto;
				stringAuxiliar = to_string(intAuxiliar);
				produtos.alterar(contador)->replace(posicaoAux, distanciaAux, stringAuxiliar);
			}
		}
	}
	else
	{
		cout << "Não a quantidade suficiente do produto no fornecedor" << endl;
	}
}