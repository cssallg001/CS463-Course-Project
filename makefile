all: main
main: main.cpp
	g++ main.cpp -o main
	./main
	rm main
