#include <stdio.h>
#include <stdlib.h>

struct st_jumsu {
    char name[20];
    int jumsu[3];
    int sum;
    float avg;
    char grade;
};

char getGrade(float score);
void makeJumsu(struct st_jumsu* p);
void printJumsu(struct st_jumsu* p);
int getClassSum(struct st_jumsu* data[], int size, int index);

int main(void) 
{
    struct st_jumsu* jdata[20];
    int sum_class[3];
    float average_class[3];
    char class_name[3][20] = {"Korean", "English", "Math"};
    int all;
    int i;
    int j;

    scanf("%d", &all);
    for (i = 0; i < all; ++i) {
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        scanf("%s %d %d %d", jdata[i]->name, &jdata[i]->jumsu[0], &jdata[i]->jumsu[1], &jdata[i]->jumsu[2]);
        makeJumsu(jdata[i]);
    }

    for (i = 0; i < all; ++i) {
        printJumsu(jdata[i]);
    }

    for (j = 0; j < 3; ++j) {
        sum_class[j] = getClassSum(jdata, all, j);
        average_class[j] = sum_class[j] / (float)all;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    for (i = 0; i < all; ++i) {
        free(jdata[i]);
        jdata[i] = NULL;
    }

    return 0;
}

char getGrade(float score) 
{
    if (score >= 90.0) {
        return 'A';
    } else if (score >= 80.0) {
        return 'B';
    } else if (score >= 70.0) {
        return 'C';
    } else if (score >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

void makeJumsu(struct st_jumsu* p) 
{
    p->sum = p->jumsu[0] + p->jumsu[1] + p->jumsu[2];
    p->avg = p->sum / 3.0;
    p->grade = getGrade(p->avg);
}

void printJumsu(struct st_jumsu* p) 
{
    printf("%s %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}

int getClassSum(struct st_jumsu* data[], int size, int index) 
{
    int sum = 0;
    int i;
    for (i = 0; i < size; ++i) {
        sum += data[i]->jumsu[index];
    }
    
    return sum;
}
