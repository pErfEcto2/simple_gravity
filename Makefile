mainFile = main.cpp
starLib = Star.cpp
systemLib = System.cpp

Star.o: $(starLib)
	g++ -c $(starLib)

System.o: $(systemLib)
	g++ -c $(systemLib)

main.o: $(mainFile)
	g++ -c $(mainFile)

build: main.o System.o Star.o
	g++ Star.o System.o main.o -lsfml-graphics -lsfml-window -lsfml-system -o app