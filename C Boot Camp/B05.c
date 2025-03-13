#include <stdio.h>

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
        sum_student[i] = 0;
    }

    for (j = 0; j < 3; ++j) {
        sum_class[j] = 0;
    }
    
    for (i = 0; i < 5; ++i) {
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum_student[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
        average_student[i] = sum_student[i] / 3.0;
        if (average_student[i] >= 90 ) {
            grade[i] = 'A';
        } else if (average_student[i] >= 80 ) {
            grade[i] = 'B';
        } else if (average_student[i] >= 70 ) {
            grade[i] = 'C';
        } else if (average_student[i] >= 60 ) {
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        }
    }

    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 3; ++j) {
            sum_class[j] += jumsu[i][j];
        }
    }

    for (j = 0; j < 3; ++j) {
        average_class[j] = sum_class[j] / 5.0;
    }

    for (i = 0; i < 5; ++i) {
        printf("%d) %d %.1f %c\n",i + 1, sum_student[i], average_student[i], grade[i]);
    }

    for (j = 0; j < 3; ++j) {
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    return 0;
}
