#include <stdio.h>

#define N 20000
int f[N][N];

int main() {
    int i, j, r;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            f[i][j] = i - j;
    for (i = 1; i < N; ++i)
        for (j = 0; j < N; ++j)
            f[i][j] += f[i-1][j];
    for (i = 0; j < N; ++j)
        r += f[N-1][j];
    printf("%d\n", r);
    return 0;
}
