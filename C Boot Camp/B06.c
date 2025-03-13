#include <stdio.h>

int studentSum(int s[5][3], int number);
char getGrade(float score);
int classSum(int s[5][3], int number);

int main(void) 
{
    int jumsu[5][3];
    int sum_student[5];
    float average_student[5];
    char grade[5];
    int sum_class[3];
    float average_class[3];
    char class_name[3][20] = {"Korean", "English", "Math"};
    int i;
    int j;

    for (i = 0; i < 5; ++i) {
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum_student[i] = studentSum(jumsu, i);
        average_student[i] = sum_student[i] / 3.0;
        grade[i] = getGrade(average_student[i]);
    }

    for (j = 0; j < 3; ++j) {
        sum_class[j] = classSum(jumsu, j);
        average_class[j] = sum_class[j] / 5.0;
    }

    for (i = 0; i < 5; ++i) {
        printf("%d) %d %.1f %c\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }

    for (j = 0; j < 3; ++j) {
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    return 0;
}

int studentSum(int s[5][3], int number) 
{
    return s[number][0] + s[number][1] + s[number][2];
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

int classSum(int s[5][3], int number) 
{
    int sum = 0;
    int i;

    for (i = 0; i < 5; ++i) {
        sum += s[i][number];
    }
    
    return sum;
}
