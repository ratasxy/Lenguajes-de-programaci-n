#include <stdio.h>

int a;

int fun() {
    a += 10;
    return a;
}

int main() {
    int b;
    a = 10;
    b = a + fun();
    printf("With the function call on the right, b is %d\n", b);
    a = 10;
    b = fun() + a;
    printf("With the function call on the left, b is %d\n", b);
    return 0;
}
