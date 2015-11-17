typedef struct {
    int x;
} sa;
typedef struct {
    int x;
} sb;

int main() {
    sa x = {5};
    sa y = x;
    sb z = x; /* Even though they have the same structure,
                 structs are not compatible with each other */
    return 0;
}
