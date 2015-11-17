int main() {
    int i = 5;
    float f = 4.5;
    char c = 'a'; 
    double d;
    d = i + f + c; /* int, float, char & double are compatible with each other */
    d = f % 5; /* float is not compatible with modulo operator */
    return 0;
}
