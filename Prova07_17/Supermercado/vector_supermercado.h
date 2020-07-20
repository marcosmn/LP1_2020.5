#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

template<class T>
class Vetor
{
private:
	size_t quantidade;
	int capacidade;
	int topo;
	T* elementos;

public:
	Vetor()
	{
		this->quantidade = 0;
		this->capacidade = 10;
		this->topo = -1;
		this->elementos = new T[capacidade];
	}

	void push_back(T elemento)
	{
		//if (quantidade == capacidade)
		if (topo == (capacidade-1))
		{
			cout << "Fila cheia, aumentando capacidade..." << endl;
			T* elementosAux = new T[capacidade];

			//elementosAux = elementos;
			for (int posicao = 0; posicao < capacidade; ++posicao)
			{
				elementosAux[posicao] = this->elementos[posicao];
			}

			delete [] elementos;
			this->capacidade = capacidade*2;
			elementos = new T[capacidade];

			//elementos = elementosAux;
			for(int posicao = 0; posicao < topo+1; ++posicao)
			{
				this->elementos[posicao] = elementosAux[posicao];
			}
			
			//this->elementos[++topo] = elemento;
			//this->quantidade++;

			push_back(elemento);
		}
		else
		{
			this->elementos[++topo] = elemento;
			this->quantidade++;
		}
	}

	void pop_back()
	{
		if (topo == -1)
		{
			cout << "Fila vazia" << endl;
		}
		else
		{
			this->elementos[topo--];
			this->quantidade--;
		}
	}

	bool isEmpty()
	{
		if (topo == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int tamanho()
	{
		return this->topo;
	}

	T* inicio()
	{
		return &this->elementos[0];
	}

	T back()
	{
		return this->elementos[topo];
	}

	T elementoPosicao(int posicao)
	{
		return this->elementos[posicao];
	}

	T* alterar(int posicao)
	{
		return &this->elementos[posicao];
	}
};