all: test testsym

clean:
	rm -f *.so test testsym

liboverride.so : override.c
	$(CC) -Wall -shared -fPIC -o liboverride.so override.c

libtest.so : libtest.cpp
	$(CXX) -Wall -shared -fPIC -o libtest.so libtest.cpp

libtestsym.so : libtest.cpp
	$(CXX) -Wall -shared -fPIC -Wl,-Bsymbolic-functions -Wl,--dynamic-list=libtest_syms.txt libtest.cpp -o libtestsym.so

test : test.cpp libtest.so liboverride.so
	$(CXX) -Wall -L. -ltest -o test test.cpp

testsym : test.cpp libtestsym.so liboverride.so
	$(CXX) -Wall -L. -ltestsym -o testsym test.cpp
