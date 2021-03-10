#include <stdio.h>
#include <stdlib.h>

struct elem{
    int live;
};

struct map{
    int n;
    int m;
    struct elem **arr;
};

void evolve(struct map* cur) {
    struct elem **new;
    new = (struct elem**)malloc(sizeof(struct elem*) * cur->n);
    for (int i = 0; i < cur->n; i++) {
        new[i] = (struct elem*)malloc(sizeof(struct elem*) * cur->m);
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
    /*struct map a;
    scanf("%d %d", &a.n, &a.m);
    a.arr = (struct elem**)(malloc(sizeof(struct elem*) * a.n));
    for (int i = 0; i < a.n; i++) {
        a.arr[i] = (struct elem*)malloc(sizeof(struct elem*) * a.m);
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