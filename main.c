#include <stdio.h>
#include <stdlib.h>

struct {
    int live;
} elem_t;

struct map{
    int n;
    int m;
    struct elem_t **arr;
} map_t;

void evolve() {

}
void game() {

}
int main() {
    struct map a;
    int n, m;
    scanf("%d %d", &n, &m);
    a.arr = (int**)(malloc(sizeof(int*) * n));
    return 0;
}