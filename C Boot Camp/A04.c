#include <stdio.h>

int main(void)
{
    int height[10], weight[10];
    float bmi[10];
    int i;
    int count = 0;

    for (i = 0; i < 10; ++i) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi[i] = weight[i] / ((height[i] / 100.0) * (height[i] / 100.0));
    
    }
    for (i = 0; i < 10; ++i) {
        if (bmi[i] >= 25.0) {
            printf("%d ", i + 1);
            count++;
        }
    }
    printf("\n%d\n", count);
    
    return 0;
}
