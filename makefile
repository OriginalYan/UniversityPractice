all: main
main: main_screen.o clear.o pr2.o
	g++ main_screen.o clear.o pr2.o -o help

main_screen.o: 
	g++ -c ./src/main_screen.cpp
clear.o:
	g++ -c ./src/clear.cpp
pr2.o:
	g++ -c ./src/pr2.cpp
	
test: test.o
	g++ test.o -o test	
test.o:
	g++ -c ./unit_test/test.cpp -I /usr/local/include/catch2
valgrind: 
	valgrind ./help 
clean:
	rm -rf *.o
	rm help
	rm test