#include <stdio.h>

int bmiLevel(int height, int weight);

int main(void)
{
    int height[10], weight[10];
    int bmi_level[10];
    int count = 0;
    int i;

    for (i = 0; i < 10; ++i) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
    }
    
    for (i = 0; i < 10; ++i) {
        if (bmi_level[i] >= 3) {
            printf("%d ", i + 1);
            count++;
        }
    }
    printf("\n%d", count);
    
    return 0;
}

int bmiLevel(int height, int weight)
{
    float bmi;
    bmi = weight / ((height / 100.0) * (height / 100.0));

    if (bmi >= 30.0) {
        return 4;
    } else if (bmi >= 25.0) {
        return 3;
    } else if (bmi >= 23.0) {
        return 2;
    } else if (bmi >= 18.5) {
        return 1;
    } else {
        return 0;
    }
}
