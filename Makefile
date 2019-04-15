all: image

image: *.cpp
	g++ -std=c++11 -ggdb -o image *.cpp
	
tests: *.cpp
	g++ -std=c++11 -DTESTS -I../gtest/include ../gtest/lib/gtest_main.a -lpthread -ggdb -o UEB2_tests *.cpp

run: image
	drmemory -- image
	
run_tests: tests
	drmemory -- UEB2_tests
	
	
clean:
	rm -f image.exe image UEB*_tests.exe UEB*_tests *.