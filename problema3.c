#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dim 100

typedef char sir[10];

void cit(double mat[dim][dim], int *N, int *M) {
    int i, j;

    ///printf("dati nr de linii=");
    scanf("%d", N);
    ///printf("dati nr de coloane=");
    scanf("%d", M);
    for (i = 0; i < *N; i++) {
        for ( j = 0; j < *M; j++) {
        ///printf("a[%d][%d]=",i,j);
            scanf("%lf", &mat[i][j]);
        }
    }
}

void tip(double mat[dim][dim], int N, int M) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%8.3lf", mat[i][j]);
        printf("\n");
    }
}

void copie(double dest[dim][dim], int N, int M, double sursa[dim][dim]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            dest[i][j] = sursa[i][j];
}

void blur(int N, int M, double a[dim][dim], double b[dim][dim]) {
    int i, j;
    double ct = 1.0 / 16.0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (i == 0 || j ==0 || i == N-1 || j == M-1) {
                b[i][j] = a[i][j];
            } else {
                b[i][j] = ct*(a[i - 1][j - 1] + 2 * a[i - 1][j] + a[i - 1][j + 1]
                + 2 * a[i][j - 1] + 4 * a[i][j]+ 2 * a[i][j + 1] + a[i + 1][j - 1]
                + 2 * a[i + 1][j] + a[i + 1][j + 1]);
            }
        }
    }
}

void smooth(int N, int M, double a[dim][dim], double b[dim][dim]) {
    int i, j;
    double ct = 1.0 / 9.0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (i == 0 || j ==0 || i == N-1 || j == M-1) {
                b[i][j] = a[i][j];
            } else  {
                b[i][j] = ct * (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1]
                + a[i][j - 1] + a[i][j] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j]
                + a[i + 1][j + 1]);
            }
        }
    }
}

int main() {
    int N, M, p, k;
    double a[dim][dim], b[dim][dim];
    sir op[dim];
    cit(a,&N,&M);

    scanf("%d", &p);
    for (k = 1; k <= p; k++) {
        scanf("%s", op[k]);
        if (strcmp(op[k], "blur") == 0) {
            blur(N, M, a, b);
        } else  {
            smooth(N, M, a, b);
        }
        copie(a, N, M, b);
    }
    ///printf("\nrezultat\n");
    tip(a, N, M);
}
