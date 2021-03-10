#include "tester.h"

void test(int cnt) {
    for (int q = 0; q < cnt; q++) {
        map test;
        generate(&test);
        printf("test case №%d\n", q + 1);
        int day = 0;
        printf("day №%d\n", day);
        for (int i = 0;i < test.n; i++) {
            for (int j = 0; j < test.m; j++) {
                printf("%d ", test.arr[i][j]);
            }
            printf("\n");
        }
        while (17) {
            int now = evolve(&test);
            if (!now) break;
            day++;
            printf("day №%d\n", day);
            for (int i = 0;i < test.n; i++) {
                for (int j = 0; j < test.m; j++) {
                    printf("%d ", test.arr[i][j]);
                }
                printf("\n");
            }
        }
    }
}