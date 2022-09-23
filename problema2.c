#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void dec_to_bin(int n, char s[]) {
    int i;
    s[16] = '\0';
    for ( i = 0; i <= 15; i++)
        s[i] = '0';
    i = 15;
    while (n != 0) {
       s[i] = (char)( 48 + n % 2);
       n = n / 2;
       i--;
    }
}

int bin_to_dec(char s[]) {
    int x = 0, p = 1,i;
    for (i = 15; i >= 0; i--) {
        x = x + (s[i] - 48) * p;
        p = p * 2;
    }
    return x;
}

void sir_to_mat(char s[], int mat[4][4]) {
    int k = 0, i, j;
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            if (s[k] == '0') {
                mat[i][j] = 0;
            } else  {
                mat[i][j] = 1;
            }
            k++;
        }
    }
}

void mat_to_sir (int mat[4][4],char s[]) {
    int k = 0, i, j;
    s[16] ='\0';
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            if (mat[i][j] == 0) {
                s[k] = '0';
            } else {
                s[k] = '1';
            } 
            k++;
        }
    }
}

void tip_mat(int mat[4][4]) {
    int i,j;
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char s[16];
    int n, i, m, xi, yi, xf, yf, mat[4][4];
    scanf("%d", &n);
    dec_to_bin(n, s);
    sir_to_mat(s, mat);
    ///tip_mat(mat);
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
        if (mat[xi][yi] == 1) {
            if (mat[xf][yf] == 1) {
                mat[xi][yi] = 0;
                mat[xf][yf] = 0;
            } else {
                mat[xi][yi] = 0;
                mat[xf][yf] = 1;
            }
        }
    }
    mat_to_sir(mat, s);
    ///printf("\n%s",s);
    int x = bin_to_dec(s);
    printf("%d\n", x);
}
