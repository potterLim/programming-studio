#include <stdio.h>
#include <stdlib.h>

typedef struct st_person {
    char name[20];
    int birthdate;
    int age;
    int year, month, day;
} PERSON;

const char* monthnames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

void setPerson(PERSON* p);
void printPerson(PERSON* p);

int main(void)
{
    PERSON* one = (PERSON*)malloc(sizeof(PERSON));
    scanf("%s %d", one->name, &(one->birthdate));

    setPerson(one);
    printPerson(one);

    free(one);
    one = NULL;

    return 0;
}

void setPerson(PERSON* p)
{
    p->year = p->birthdate / 10000;
    int tmp = p->birthdate % 10000;
    p->month = tmp / 100;
    p->day = tmp % 100;
    p->age = 2025 - p->year;
}

void printPerson(PERSON* p) 
{
    printf("%s - %d (%s %d, %d)\n", p->name, p->age, monthnames[p->month - 1], p->day, p->year);
}
