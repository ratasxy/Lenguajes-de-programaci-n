typedef struct {
    int a, b, c;
} type_a;

typedef struct {
    int a, b, c;
} type_b;

int main() {
    type_a a = {1, 2, 3};
    type_b b;
    b = a;
    return 0;
}
