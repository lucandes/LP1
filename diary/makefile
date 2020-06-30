GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary
MATRICULA = 20190102629

all: diary pdf zip

diary: obj/main.o obj/Diary.o obj/Date.o obj/Message.o obj/Time.o obj/App.o
	$(GCC) obj/*.o -o $(PROGRAMA) -std=c++11

obj/main.o:	src/main.cpp
	$(GCC) -c src/main.cpp $(GCC_FLAGS) -o obj/main.o

obj/Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) -c src/Diary.cpp $(GCC_FLAGS) -o obj/Diary.o

obj/Date.o:	src/Date.cpp include/Date.h
	$(GCC) -c src/Date.cpp $(GCC_FLAGS) -o obj/Date.o

obj/Message.o: src/Message.cpp include/Message.h
	$(GCC) -c src/Message.cpp $(GCC_FLAGS) -o obj/Message.o

obj/Time.o: src/Time.cpp include/Time.h
	$(GCC) -c src/Time.cpp $(GCC_FLAGS) -o obj/Time.o

obj/App.o: src/App.cpp include/App.h
	$(GCC) -c src/App.cpp $(GCC_FLAGS) -o obj/App.o

clean:
	rm  obj/*.o $(PROGRAMA) db.md diary.pdf $(MATRICULA).zip -f

pdf: ./db.md 
	pandoc -f markdown -t context -o diary.pdf db.md 

zip:
	zip -r $(MATRICULA).zip .