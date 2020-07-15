# Declarando o programa
output: main.o App.o Diario.o Mensagem.o
	g++ main.o App.o Diario.o Mensagem.o -o output

# Declarando o arquivo principal
main.o: src/main.cpp
	g++ -c src/main.cpp

# Declarando os araquivos de app
App.o: src/App.cpp include/App.h
	g++ -c src/App.cpp

# Declarando os arquivos de diario
Diario.o: src/Diario.cpp include/Diario.h
	g++ -c src/Diario.cpp

# Declarando os arquivos de mensagem
Mensagem.o: src/Mensagem.cpp include/Mensagem.h
	g++ -c src/Mensagem.cpp

clean:
	rm *.o output