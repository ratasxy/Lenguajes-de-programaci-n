int main() {
    int a[5];
    int *p = a + 2; /* arrays and pointers of the same type are compatible */
    float *x = a; /* Pointers of different types are incompatible */
    return 0;
}
