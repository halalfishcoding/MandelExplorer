all: compile link run

compile:
	
	g++ -c src/*.cpp -Isrc/include
	mv *.o build/obj/

	

link:
	g++ build/obj/*.o -o build/main.exe -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm build/obj/*
	rm build/*

run:
	./build/main.exe

test:
	g++ src/*.cpp -o build/main.exe
