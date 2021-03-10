#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int calc_nieghbors(map *cur, int i, int j) {
    int cnt = 0;
    if (i > 0) {
        if (j > 0) if (cur->arr[i - 1][j - 1].live) cnt++;
        if (j < cur->m - 1) if (cur->arr[i - 1][j + 1].live) cnt++;
        if (cur->arr[i - 1][j].live) cnt++;
    }
    if (i < cur->n) {
        if (j > 0) if (cur->arr[i + 1][j - 1].live) cnt++;
        if (j < cur->m - 1) if (cur->arr[i + 1][j + 1].live) cnt++;
        if (cur->arr[i + 1][j].live) cnt++;
    }
    if (j > 0) if (cur->arr[i][j - 1].live) cnt++;
    if (j < cur->m - 1) if (cur->arr[i][j + 1].live) cnt++;
    return cnt;
}

void evolve(map* cur) {
    elem **new;
    new = (elem**)malloc(sizeof(elem*) * cur->n);
    for (int i = 0; i < cur->n; i++) {
        new[i] = (elem*)malloc(sizeof(elem*) * cur->m);
        for (int j = 0; j < cur->m; j++) {
            int nieghnors = calc_nieghbors(&cur, i, j);
            new[i][j] = cur->arr[i][j];
            if (nieghnors == 3) {
                new[i][j].live = 1;
            }
            if (nieghnors < 2 && nieghnors > 3) {
                new[i][j].live = 0;
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
    }
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            printf("%d ", a.arr[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}