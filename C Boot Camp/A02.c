#include <stdio.h>

int main(void)
{
    int height, weight;
    float bmi;

    scanf("%d %d", &height, &weight);
    bmi = weight / ((height / 100.0) * (height / 100.0));
    
    printf("%.1f ", bmi);
    if (bmi >= 25) {
        printf("Overweight");
    } else {
        printf("Normal");
    }
    
    return 0;
}
