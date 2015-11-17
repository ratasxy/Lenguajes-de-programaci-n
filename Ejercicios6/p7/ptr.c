#include <stdio.h>

#define N 20000
int f[N][N];

int main() {
    int i, j, r;
    int *p = f[0];
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            *(p + i * N + j) = i - j;
    for (i = 1; i < N; ++i)
        for (j = 0; j < N; ++j)
            *(p + i * N + j) += *(p + (i-1) * N + j);
    for (i = 0; j < N; ++j)
        r += *(p + (N - 1) * N + j);
    printf("%d\n", r);
    return 0;
}
