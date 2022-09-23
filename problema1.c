#include <stdio.h>
#include <stdlib.h>

void intersectie(int x1, int x2, int x3, int x4, int *x5, int *x6) {
    if (x1 == 0 && x2 == -1) {
        *x5 = 0;
        *x6 = -1;
    } else if (x3 > x2 || x1 > x4) {
        *x5 = 0;
        *x6 = -1;
    } else {
        *x5 = x1 > x3 ? x1 : x3;
        *x6 = x2 < x4 ? x2 : x4;
    }
}

void reuniune (int x1, int x2, int x3, int x4, int *x5, int *x6) {
   if (x1 == 0 && x2 == -1) {
        *x5 = x3;
        *x6 = x4;
    } else {
        *x5 = x1 < x3 ? x1 : x3;
        *x6 = x2 > x4 ? x2 : x4;
    }
}

int main() {
///1-intersectie
///2-reuniune extinsa
///tipul interogarii : 1 sau 2
    int x1, x2, x3, x4, v[100], *x5, *x6, i, j, nop, N;
    int op, inter;
    int vida;
    x5 = (int *)malloc(sizeof(int));
    x6 = (int *)malloc(sizeof(int));
    ///printf("Nr de interogari:");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &inter);
        if (inter == 1) {
            ///op simpla
            scanf("%d", &op);
            scanf("%d %d %d %d",&x1, &x2, &x3, &x4);
            if (op == 1) {
                ///intersectie
                intersectie(x1, x2, x3, x4, x5, x6);
                if (*x5 == 0 && *x6 == -1) {
                    printf("%d\n",0);
                } else {
                    printf("%d %d\n",*x5,*x6);
                } 
            } else {
                ///reuniune extinsa
                reuniune(x1, x2, x3, x4, x5, x6);
                printf("%d %d\n",*x5,*x6);
            }
        } else {
            ///op compusa
            scanf("%d", &nop);
            for (j = 1; j <= nop; j++)
                  scanf("%d",&v[j]);
            vida = 0;
            *x5 = 0;
            *x6 = -1;
            scanf("%d %d",&x1, &x2);
            for (j = 1; j <= nop; j++) {
                scanf("%d %d", &x3, &x4);
                if (vida==0) {
                    if (v[j] == 1) {
                        intersectie(x1, x2, x3, x4, x5, x6);
                    } else {
                        reuniune(x1, x2, x3, x4, x5, x6);
                    }
                } else if (v[j] == 1) {
                        ///printf("%d\n",0);
                        vida = 1; 
                        *x5 = 0;
                        *x6 = -1;
                    } else {
                        *x5 = x3;
                        *x6 = x4;
                    }
                x1 = *x5;
                x2 = *x6;
            }
            if (*x5 == 0 && *x6 == -1) {
                printf("%d\n",0);
            } else {
                printf("%d %d\n",*x5,*x6);
            }
        }
    }
    return 0;
}
