#include <stdio.h>

int main(void)
{
    int height, weight;
    float bmi;
    int i;
    int count_person;
    int count_overweight = 0;

    scanf("%d", &count_person);

    for (i = 0; i < count_person; ++i) {
        scanf("%d %d", &height, &weight);
        bmi = weight / ((height / 100.0) * (height / 100.0));
    
        if (bmi >= 25.0) {
            count_overweight++;
        }
    }
    printf("%d", count_overweight);
    
    return 0;
}
