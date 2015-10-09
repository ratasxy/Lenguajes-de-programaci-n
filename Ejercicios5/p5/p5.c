#include <stdio.h>

string bibble;

void cEsGenial() {
    bibble = "Es mi perro";  /* global variable */
    int bibble;
    bibble = "Es mi cachorro";  /* local variable */
    printf("%s\n", bibble);  /* print local variable */
}

int main() {
    cEsGenial();
    printf("%s\n", bibble);  /* print global variable */
}
