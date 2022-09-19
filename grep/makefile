main_demo:main.o grep.o
	g++ -o main_demo main.o grep.o
main.o:main.cpp grep.h
	g++ -g -c main.cpp
grep.o:grep.cpp grep.h
	g++ -g -c grep.cpp
.CEN:clean
clean:
	rm main_demo main.o grep.o

