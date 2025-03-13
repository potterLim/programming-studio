#include <stdio.h>

int main(void)
{
    int kor, eng, math;
    int total;
    float average;
    char grade;
    
    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    if (average >= 90.0) {
        grade = 'A';
    } else if (average >= 80.0) {
        grade = 'B';
    } else if (average >= 70.0) {
        grade = 'C';
    } else if (average >= 60.0) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("%.1f %c\n", average, grade);
    return 0;
}
