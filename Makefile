out: clean compile execute

compile: main.cpp
	g++ -g -Wall -std=c++14 main.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe

test:
	g++ -g -Wall -std=c++14 SoftwareTest.cpp -o test.exe