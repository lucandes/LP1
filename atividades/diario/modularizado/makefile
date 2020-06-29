all: main.o Diary.o Date.o Message.o Time.o App.o
	g++ main.o Diary.o Date.o Message.o Time.o App.o -o main
main.o:
	g++ -c src/main.cpp -I include/ -std=c++11
Diary.o:
	g++ -c src/Diary.cpp -I include/ -std=c++11
Date.o:
	g++ -c src/Date.cpp -I include -std=c++11
Message.o:
	g++ -c src/Message.cpp -I include -std=c++11
Time.o:
	g++ -c src/Time.cpp -I include -std=c++11
App.o:
	g++ -c src/App.cpp -I include -std=c++11
clean:
	rm  *.o main db.md

