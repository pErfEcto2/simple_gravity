mainFile = jumps.cpp

jumps.o: $(mainFile)
	g++ -c $(mainFile)

build: jumps.o
	g++ jumps.o -lsfml-graphics -lsfml-window -lsfml-system -o jumps