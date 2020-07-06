GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = bank
MATRICULA = 20190102629

all: obj/ bank

obj/:
	mkdir ./obj/

bank: obj/main.o obj/Account.o
	$(GCC) obj/*.o -o $(PROGRAMA) $(GCC_FLAGS)

obj/main.o:	src/main.cpp
	$(GCC) -c src/main.cpp $(GCC_FLAGS) -o obj/main.o

obj/Account.o: src/Account.cpp
	$(GCC) -c src/Account.cpp $(GCC_FLAGS) -o obj/Account.o

zip:
	zip -r $(MATRICULA).zip .

clean:
	rm -drf obj/ $(PROGRAMA) $(MATRICULA).zip