#include <stdio.h>

struct st_jumsu {
    char name[20];
    int jumsu[3];
    int sum;
    float avg;
    char grade;
};

char getGrade(float score);

int main(void) 
{
    struct st_jumsu one;

    scanf("%s %d %d %d", one.name, &one.jumsu[0], &one.jumsu[1], &one.jumsu[2]);

    one.sum = one.jumsu[0] + one.jumsu[1] + one.jumsu[2];
    one.avg = one.sum / 3.0;
    one.grade = getGrade(one.avg);

    printf("%s %d %.1f %c\n", one.name, one.sum, one.avg, one.grade);
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
