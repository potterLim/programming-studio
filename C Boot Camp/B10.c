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
struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index);
int countGrade(struct st_jumsu* data[], int size, char grade);

int main(void) 
{
    struct st_jumsu* jdata[20];
    int sum_class[3];
    float average_class[3];
    char class_name[3][20] = {"Korean", "English", "Math"};
    struct st_jumsu* first[3];
    char grades[5] = "ABCDF";
    int count_grade[5];
    int count;
    int i;
    int j;
    
    scanf("%d", &count);
    for (i = 0; i < count; ++i) {
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        scanf("%s %d %d %d", jdata[i]->name, &jdata[i]->jumsu[0], &jdata[i]->jumsu[1], &jdata[i]->jumsu[2]);
        makeJumsu(jdata[i]);
    }
    
    for (i = 0; i < count; ++i) {
        printf("%d) ", i + 1);
        printJumsu(jdata[i]);
        printf("\n");
    }
    
    for (j = 0; j < 3; ++j) {
        sum_class[j] = 0;
        for (i = 0; i < count; ++i) {
            sum_class[j] += jdata[i]->jumsu[j];
        }
        average_class[j] = sum_class[j] / (float)count;
    }
    
    for (j = 0; j < 3; ++j) {
        first[j] = firstRanking(jdata, count, j);
        printf("[%s] %s %d\n", class_name[j], first[j]->name, first[j]->jumsu[j]);
    }
    
    for (i = 0; i < 5; ++i) {
        count_grade[i] = countGrade(jdata, count, grades[i]);
        printf("[%c] %d\n", grades[i], count_grade[i]);
    }
    
    for (i = 0; i < count; ++i) {
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
    printf("%s - %d %.1f %c", p->name, p->sum, p->avg, p->grade);
}

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index) 
{
    int i;
    int max = data[0]->jumsu[index];
    int maxIndex = 0;

    for (i = 1; i < size; ++i) {
        if (data[i]->jumsu[index] > max) {
            max = data[i]->jumsu[index];
            maxIndex = i;
        }
    }

    return data[maxIndex];
}

int countGrade(struct st_jumsu* data[], int size, char grade) 
{
    int i;
    int count = 0;

    for (i = 0; i < size; ++i) {
        if (data[i]->grade == grade) {
            ++count;
        }
    }
    
    return count;
}
