all: add-nbo

add-nbo: main.o nbo.o
	g++ -o add-nbo main.o nbo.o

main.o: main.cpp nbo.h
	g++ -c main.cpp

nbo.o: nbo.cpp nbo.h
	g++ -c nbo.cpp

clean:
	rm *.o add-nbo

