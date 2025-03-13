#include <stdio.h>

struct bmi_struct {
    char name[20];
    int height, weight;
    float bmi;
    int bmi_level;
};

void bmiResolve(struct bmi_struct* sp);

int main(void) 
{
    struct bmi_struct data;
    char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight", "Mild obesity", "Severe obesity"};

    scanf("%s %d %d", data.name, &data.height, &data.weight);
    bmiResolve(&data);
    
    printf("%s, You are %s.\n", data.name, bmi_string[data.bmi_level]);
    return 0;
}

void bmiResolve(struct bmi_struct* sp) 
{
    sp->bmi = sp->weight / ((sp->height / 100.0) * (sp->height / 100.0));

    if (sp->bmi >= 30.0) {
        sp->bmi_level = 4;
    } else if (sp->bmi >= 25.0) {
        sp->bmi_level = 3;
    } else if (sp->bmi >= 23.0) {
        sp->bmi_level = 2;
    } else if (sp->bmi >= 18.5) {
        sp->bmi_level = 1;
    } else {
        sp->bmi_level = 0;
    }
}
