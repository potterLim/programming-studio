#include <stdio.h>
#include <stdlib.h>

struct bmi_struct {
    char name[20];
    int height, weight;
    float bmi;
    int bmi_level;
};

int loadData(struct bmi_struct* list[]);
void bmiResolve(struct bmi_struct* sp);
void printBmiData(struct bmi_struct* list[], int size);

char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight", "Mild obesity", "Severe obesity"};

int main(void) 
{
    struct bmi_struct* data[20];
    int count;
    int i;

    count = loadData(data);
    printf("Loaded %d\n", count);

    for (i = 0; i < count; ++i) {
        bmiResolve(data[i]);
    }

    printBmiData(data, count);
    for (i = 0; i < count; ++i) {
        free(data[i]);
        data[i] = NULL;
    }

    return 0;
}

int loadData(struct bmi_struct* list[]) 
{
    int n;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        list[i] = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
        scanf("%s %d %d", list[i]->name, &list[i]->height, &list[i]->weight);
    }

    return n;
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

void printBmiData(struct bmi_struct* list[], int size) 
{
    int i;

    for (i = 0; i < size; ++i) {
        printf("%s %dcm %dkg %.1f %s\n", list[i]->name, list[i]->height, list[i]->weight, list[i]->bmi, bmi_string[list[i]->bmi_level]);
    }
}
