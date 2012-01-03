#include <stdio.h>

extern "C" void foo()
{
    printf("original foo called\n");
}

extern "C" void test_foo()
{
    foo();
}
