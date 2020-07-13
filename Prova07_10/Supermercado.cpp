#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#include "Estabelecimento.h"
#include "Cliente.h"

using namespace std;

int main()
{
    std::cout << "Bem vindo ao supermercado!\n";

	// Abrindo estabelecimento
	Estabelecimento estabelecimento;
	bool continuar = true;
	while(continuar)
	{
		// Menu do cliente
		double saldoCliente = 0.0;
		cout << "Informe o saldo do cliente:" << endl;
		cin >> saldoCliente;

		Cliente cliente(saldoCliente);

		bool emCompras = true;
		while(emCompras)
		{
			int acao = 0;
			cout << "Acoes:" << endl;
			cout << "Finalizar compras - 0" << endl;
			cout << "Verificar produtos da loja - 1" << endl;
			cout << "Ver conteudo da sacola - 2" << endl;
			cout << "Ver o caixa - 3" << endl;
			cout << "Comprar item - 4" << endl;
			cin >> acao;

			int codigoCompra = 0;
			switch(acao)
			{
			case 0:
				cout << "=============================================" << endl;
				cout << "Finalizando compras..." << endl;
				estabelecimento.caixa();
				cout << "=============================================" << endl;
				cliente.registro();
				emCompras = false;
				break;
			case 1:
				cout << "=============================================" << endl;
				cout << "Verificando loja..." << endl;
				estabelecimento.listar();
				cout << "=============================================" << endl;
				break;
			case 2:
				cout << "=============================================" << endl;
				cout << "Abrindo sacola..." << endl;
				cliente.verSacola();
				cout << "=============================================" << endl;
				break;
			case 3:
				cout << "=============================================" << endl;
				cout << "Vendo o caixa..." << endl;
				estabelecimento.caixa();
				cout << "=============================================" << endl;
				break;
			case 4:
				cout << "=============================================" << endl;
				cout << "Digite o codigo do produto: ";
				cin >> codigoCompra;

				cout << "\nComprando produto..." << endl;
				estabelecimento.venda(&cliente, codigoCompra);
				cout << "=============================================" << endl;
				break;
			default:
				cout << "Acao invalida..." << endl;
				break;
			}
		}

		cout << "Deseja inicializar um novo cliente? (1 = sim / 0 = não)" << endl;
		cin >> continuar;
	}
	cout << "\n Obrigado e volte sempre!" << endl;

	return 0;
}
