#include <stdio.h>

int studentSum(int s[20][3], int size, int index);
char getGrade(float score);
int classSum(int s[20][3], int size, int number);
int firstRanking(int s[20], int size);

int main(void) 
{
    int jumsu[20][3];
    int sum_student[20];
    float average_student[20];
    char grade[20];
    int sum_class[3];
    float average_class[3];
    char class_name[3][20] = {"Korean", "English", "Math"};
    int all;
    int i; 
    int j;
    int first;

    scanf("%d", &all);
    for (i = 0; i < all; ++i) {
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum_student[i] = studentSum(jumsu, all, i);
        average_student[i] = sum_student[i] / 3.0;
        grade[i] = getGrade(average_student[i]);
    }

    for (i = 0; i < all; ++i) {
        printf("%d) %d %.1f %c\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }

    for (j = 0; j < 3; ++j) {
        sum_class[j] = classSum(jumsu, all, j);
        average_class[j] = sum_class[j] / (float)all;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    first = firstRanking(sum_student, all);
    printf("1st Ranking: %d\n", first + 1);
    return 0;
}

int studentSum(int s[20][3], int size, int index) 
{
    return s[index][0] + s[index][1] + s[index][2];
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

int classSum(int s[20][3], int size, int number) 
{
    int sum = 0;
    int i;

    for (i = 0; i < size; ++i) {
        sum += s[i][number];
    }

    return sum;
}

int firstRanking(int s[20], int size) 
{
    int maxIndex = 0;
    int i;

    for (i = 1; i < size; ++i) {
        if (s[i] > s[maxIndex]) {
            maxIndex = i;
        }
    }
    
    return maxIndex;
}
