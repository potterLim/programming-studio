#include <stdio.h>

int main(void)
{
    int kor, eng, math;
    int total;
    float average;
    
    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%d %.1f\n", total, average);
    return 0;
}
