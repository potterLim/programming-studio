#include <stdio.h>

int bmiLevel(int height, int weight);

int main(void) 
{
    int height[10], weight[10];
    int bmi_level[10];
    int all, i;
    char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight", "Mild obesity", "Severe obesity"};

    scanf("%d", &all);
    for (i = 0; i < all; ++i) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
    }

    for (i = 0; i < all; ++i) {
        if (bmi_level[i] >= 3) {
            printf("%d %s\n", i + 1, bmi_string[bmi_level[i]]);
        }
    }

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
