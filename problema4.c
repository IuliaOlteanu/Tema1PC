#include <stdio.h>
#include <stdlib.h>
///l-linie , v-valoare
typedef struct {int l,v;} el;
void citire(int A[][100], int n, int m) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    }
}
void afisare(int A[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d", A[i][j]);
        printf("\n");
    }
}

int suma_linie(int A[][100], int n, int m, int l) {
    int suma = 0;
    int i;
    for (i = 0; i < m; i++)
        suma = suma + A[l][i];
    return suma;
}

 ///o apelez suma_linie(a,n,m,i) / suma elem de pe linia i
 void sort_cresc(el v[],int n) {
    ///ordonez crescator dupa valoare
    ///la valori egale ordonez dupa linie
    int ok = 0, i;
    el aux;
    while (ok == 0) {
        ok = 1;
        for (i = 0; i < n - 1; i++) {
            if (v[i].v > v[i + 1].v) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = 0;
            } else if (v[i].v == v[i + 1].v) {
                    if(v[i].l > v[i + 1].l) {
                        aux = v[i];
                        v[i] = v[i + 1];
                        v[i + 1] = aux;
                        ok = 0; 
                    }
            }
        }
    }
}
int main() {
    int a[100][100], n, m, k, i;
    el v[100];
    scanf("%d%d", &n, &m);
    citire(a, n, m);
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        v[i].v = suma_linie(a, n, m, i);
        v[i].l = i;
    }
    sort_cresc(v, n);
    for (i = 0; i <= k-1; i++) {
        if(i == k - 1) {
            printf("%d\n", v[i].l);
        } else {
            printf("%d ", v[i].l);
        }
    }

    return 0;
}
