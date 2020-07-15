GCC := g++
GCC_FLAGS := -I include -std=c++11 -Wall
PROGRAMA := diario

# Declarando o programa
$(PROGRAMA): main.o App.o Diario.o Mensagem.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o App.o Diario.o Mensagem.o

# Declarando o arquivo principal
main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

# Declarando os araquivos de app
App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

# Declarando os arquivos de diario
Diario.o: src/Diario.cpp include/Diario.h
	$(GCC) $(GCC_FLAGS) -c src/Diario.cpp

# Declarando os arquivos de mensagem
Mensagem.o: src/Mensagem.cpp include/Mensagem.h
	$(GCC) $(GCC_FLAGS) -c src/Mensagem.cpp
  
doc.html: diario.md
	pandoc -f markdown -t html -o doc.html
