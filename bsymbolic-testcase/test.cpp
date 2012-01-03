#include <stdio.h>

extern "C" int test_foo(void);

int main(void)
{
    printf("%d\n", test_foo());
    return 0;
}
