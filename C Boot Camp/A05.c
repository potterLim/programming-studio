#include <stdio.h>

int bmiLevel(int height, int weight);

int main(void)
{
    int height, weight;
    int bmi_level;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%d %d", &height, &weight);
    bmi_level = bmiLevel(height, weight);
    printf("%s (%d)\n", bmi_string[bmi_level], bmi_level);
    
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
