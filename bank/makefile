GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = banco
MATRICULA = 20190102629

all: obj/ banco

obj/:
	mkdir ./obj/

banco: obj/main.o obj/Conta.o obj/Cliente.o obj/ClientePJ.o obj/Agencia.o obj/Fila.o
	$(GCC) obj/*.o -o $(PROGRAMA) $(GCC_FLAGS)

obj/main.o:	src/main.cpp
	$(GCC) -c src/main.cpp $(GCC_FLAGS) -o obj/main.o

obj/Conta.o: src/Conta.cpp include/Conta.hpp
	$(GCC) -c src/Conta.cpp $(GCC_FLAGS) -o obj/Conta.o

obj/Cliente.o: src/Cliente.cpp include/Cliente.hpp
	$(GCC) -c src/Cliente.cpp $(GCC_FLAGS) -o obj/Cliente.o

obj/ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.hpp
	$(GCC) -c src/ClientePJ.cpp $(GCC_FLAGS) -o obj/ClientePJ.o

obj/Agencia.o: src/Agencia.cpp include/Agencia.hpp
	$(GCC) -c src/Agencia.cpp $(GCC_FLAGS) -o obj/Agencia.o

obj/Fila.o: src/Fila.cpp include/Fila.hpp
	$(GCC) -c src/Fila.cpp $(GCC_FLAGS) -o obj/Fila.o

zip:
	zip -r $(MATRICULA).zip .

clean:
	rm -drf obj/ $(PROGRAMA) $(MATRICULA).zip