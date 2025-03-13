#include <stdio.h>

int main(void)
{
    int height, weight;
    float bmi;

    scanf("%d %d", &height, &weight);
    bmi = weight / ((height / 100.0) * (height / 100.0));
    printf("%.1f\n", bmi);
    
    return 0;
}
