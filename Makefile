all:
	g++ Tests.cpp -o test -lgtest
	./test
	
gcov: 
	g++ Tests.cpp -o test -lgtest -ftest-coverage -fprofile-arcs
	./test
	gcov Tests.cpp
	
check:
	cppcheck Tests.cpp --enable=warning
	
clean:
	rm *.gc*
	rm test