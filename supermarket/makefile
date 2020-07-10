GCC = g++
GCC_FLAGS = -std=c++11 -I include
PROGRAMA = market
MATRICULA = 20190102629

all: obj/ market

obj/:
	mkdir ./obj/

market: obj/main.o obj/Client.o obj/Product.o obj/Store.o
	$(GCC) -o $(PROGRAMA) $(GCC_FLAGS) obj/*.o

obj/main.o: src/main.cpp
	$(GCC) -c $(GCC_FLAGS) src/main.cpp -o obj/main.o

obj/Client.o: src/Client.cpp
	$(GCC) -c $(GCC_FLAGS) src/Client.cpp -o obj/Client.o

obj/Product.o: src/Product.cpp
	$(GCC) -c $(GCC_FLAGS) src/Product.cpp -o obj/Product.o

obj/Store.o: src/Store.cpp
	$(GCC) -c $(GCC_FLAGS) src/Store.cpp -o obj/Store.o

clean:
	rm -drf ./obj/ $(PROGRAMA) $(MATRICULA).zip

zip:
	zip -r $(MATRICULA).zip . 