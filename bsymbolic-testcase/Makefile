all: test.bin testsym.bin

clean:
	rm -f *.so test.bin testsym.bin

liboverride.so : override.c
	$(CC) -Wall -shared -fPIC -o liboverride.so override.c

libtest.so : libtest.cpp
	$(CXX) -Wall -shared -fPIC -o libtest.so libtest.cpp

libtestsym.so : libtest.cpp
	$(CXX) -Wall -shared -fPIC -Wl,-Bsymbolic-functions -Wl,--dynamic-list=libtest_syms.txt libtest.cpp -o libtestsym.so

test.bin : test.cpp libtest.so liboverride.so
	$(CXX) -Wall -L. -ltest -o test.bin test.cpp

testsym.bin : test.cpp libtestsym.so liboverride.so
	$(CXX) -Wall -L. -ltestsym -o testsym.bin test.cpp
