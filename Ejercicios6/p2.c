#include <stdlib.h>

int main() {
    int *p = malloc(5 * sizeof(int));
    free(p); /* GCC 5.2.0 implements `free` */
    return 0;
}
