#include <stdio.h>

int main(void)
{
    const char* monthnames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    char names[100][20];
    int birthdate[100];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s %d", names[i], &birthdate[i]);
    }

    int oldestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (birthdate[i] < birthdate[oldestIndex]) {
            oldestIndex = i;
        }
    }

    int year = birthdate[oldestIndex] / 10000;
    int md = birthdate[oldestIndex] % 10000;
    int month = md / 100;
    int day = md % 100;
    int age = 2025 - year;

    printf("%s - %d (%s %d, %d)\n", names[oldestIndex], age, monthnames[month - 1], day, year);

    return 0;
}
