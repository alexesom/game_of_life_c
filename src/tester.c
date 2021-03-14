#include "struct.h"

void test(int cnt) 
{
    for (int q = 0; q < cnt; q++) 
    {
        Map test;
        int day = 0;
        generate(test);

        printf("test case №%d\n", q + 1);
        printf("day №%d\n", day);

        for (int i = 0; i < test->rows; i++) 
        {
            for (int j = 0; j < test->columns; j++) 
                printf("%d ", test->matrix[i][j]);

            printf("\n");
        }

        while (17) 
        {
            int now = evolve(&test);
            if (!now) break;
            day++;
            printf("day №%d\n", day);
            for (int i = 0;i < test->rows; i++) 
            {
                for (int j = 0; j < test->columns; j++) 
                {
                    printf("%d ", test->matrix[i][j]);
                }
                printf("\n");
            }
        }
    }
}