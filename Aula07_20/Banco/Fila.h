#include <iostream>
#include <string>

using namespace std;

template<class T>
class Fila
{
private:
	int tamanho;
	int topo;
	T* elementos;

public:
	Fila(int novoTamanho)
	{
		this->tamanho = novoTamanho;
		this->topo = -1;
		this->elementos = new T[tamanho];
	}

	void push(T elemento)
	{
		if(topo == (tamanho-1))
		{
			cout << "Fila cheia" << endl;
		}
		else
		{
			this->elementos[++topo] = elemento;
		}
	}

	void pop(T elemento)
	{
		if(topo == -1)
		{
			cout << "Fila vazia" << endl;
		}
		else
		{
			this->elementos[topo--];
		}
	}

	bool isEmpty()
	{
		if(topo == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T back()
	{
		return this->elementos[topo];
	}
};