#include <stdio.h>

int main(void)
{
    const char* monthnames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    char name[20];
    int birthdate;
    int age;

    scanf("%s %d", name, &birthdate);

    int year = birthdate / 10000;
    int tmp = birthdate % 10000;
    int month = tmp / 100;
    int day = tmp % 100;

    age = 2025 - year;
    printf("%s - %d (%s %d, %d)\n", name, age, monthnames[month - 1], day, year);

    return 0;
}
