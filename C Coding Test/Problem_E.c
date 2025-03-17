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
int loadPersons(PERSON* list[]);
void printBirthdays(PERSON* list[], int size, int month);

int main(void)
{
    PERSON* persons[100];
    int count = loadPersons(persons);

    for (int month = 1; month <= 12; ++month) {
        printBirthdays(persons, count, month);
    }

    for (int i = 0; i < count; ++i) {
        free(persons[i]);
        persons[i] = NULL;
    }

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


int loadPersons(PERSON* list[])
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        list[i] = (PERSON*)malloc(sizeof(PERSON));
        scanf("%s %d", list[i]->name, &list[i]->birthdate);
        setPerson(list[i]);
    }

    return n;
}

void printBirthdays(PERSON* list[], int size, int month) 
{
    int count = 0;
    printf("[%s] ", monthnames[month - 1]);

    for (int i = 0; i < size; ++i) {
        if (list[i]->month == month) {
            printf("%s(%d) ", list[i]->name, list[i]->day);
            count++;
        }
    }
    printf("- %d\n", count);
}
