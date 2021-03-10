#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void evolve(map* cur) {
    elem **new;
    new = (elem**)malloc(sizeof(elem*) * cur->n);
    for (int i = 0; i < cur->n; i++) {
        new[i] = (elem*)malloc(sizeof(elem*) * cur->m);
        for (int j = 0; j < cur->m; j++) {
            int cnt = 0;
            if (i > 0) {
                if (j > 0) if (cur->arr[i - 1][j - 1].live == 1) cnt++;
            }
        }
    }
}
void game() {

}
int main() {
    /*map a;
    scanf("%d %d", &a.n, &a.m);
    a.arr = (elem**)(malloc(sizeof(elem*) * a.n));
    for (int i = 0; i < a.n; i++) {
        a.arr[i] = (elem*)malloc(sizeof(elem*) * a.m);
        for (int j = 0; j < a.m; j++) {
            a.arr[i][j].live = 0;
            printf("%d ", a.arr[i][j].live);
        }
        printf("\n");
    }*/
    /*for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            printf("%d ", a.arr[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}