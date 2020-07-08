#include <string>
#include "Motor.h"

using namespace std;

class Carro
{
    public:
	static int quantidadeCarros;
    string tipo;
    string placa;
    int numPortas;
    int velocidade;
    string cor;
    Motor motor;

    Carro(string cor);
    Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};
