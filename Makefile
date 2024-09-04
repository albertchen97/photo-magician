main: *.cpp
	g++ -Wall -g -o main *.cpp

clean:
	rm -f *.o main
