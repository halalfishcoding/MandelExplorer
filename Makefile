all: compile link

compile:
	g++ -c src/main.cpp -o build/main.o -Isrc/include

link:
	g++ build/main.o -o build/main.exe -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm build/*
