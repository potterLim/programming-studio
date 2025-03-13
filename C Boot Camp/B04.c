#include <stdio.h>

int main(void)
{
    int jumsu[5][3];
    int sum[5];
    float average[5];
    int i;
    
    for (i = 0; i < 5; ++i) {
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
        average[i] = sum[i] / 3.0;
    }

    for (i = 0; i < 5; ++i) {
        printf("%d) %d %.1f\n",i + 1, sum[i], average[i]);
    }

    return 0;
}
