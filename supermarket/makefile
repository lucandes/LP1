GCC = g++
GCC_FLAGS = -std=c++11 -I include
PROGRAMA = market
MATRICULA = 20190102629

all: obj/ market

obj/:
	mkdir ./obj/

market: obj/main.o obj/Client.o obj/Product.o obj/Store.o obj/Util.o
	$(GCC) -o $(PROGRAMA) $(GCC_FLAGS) obj/*.o

obj/main.o: src/main.cpp
	$(GCC) -c $(GCC_FLAGS) src/main.cpp -o obj/main.o

obj/Client.o: src/Client.cpp include/Client.hpp
	$(GCC) -c $(GCC_FLAGS) src/Client.cpp -o obj/Client.o

obj/Product.o: src/Product.cpp include/Product.hpp
	$(GCC) -c $(GCC_FLAGS) src/Product.cpp -o obj/Product.o

obj/Store.o: src/Store.cpp include/Store.hpp
	$(GCC) -c $(GCC_FLAGS) src/Store.cpp -o obj/Store.o

obj/Util.o: src/Util.cpp include/Util.hpp
	$(GCC) -c $(GCC_FLAGS) src/Util.cpp -o obj/Util.o
	
clean:
	rm -drf ./obj/ $(PROGRAMA) $(MATRICULA).zip

zip:
	zip -r $(MATRICULA).zip . 