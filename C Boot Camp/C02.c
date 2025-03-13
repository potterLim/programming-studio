#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person {
    char name[20];
    int gender;
    int country;
    int birthyear;
};

int getCountry(char* str);
void printInfo(struct st_person* p);
int countGender(struct st_person* data[], int size, int gender);

int main(void)
{
    struct st_person* pdata[20];
    char country[5];
    char count_gender[2];
    int count;
    int gender, birthyear;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; ++i) {
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));

        scanf("%19s %d %4s %d", pdata[i]->name, &gender, country, &birthyear);

        pdata[i]->gender = gender;
        pdata[i]->country = getCountry(country);
        pdata[i]->birthyear = birthyear;
    }

    for (i = 0; i < count; ++i) {
        printf("%d) ", i + 1);
        printInfo(pdata[i]);
    }

    count_gender[0] = countGender(pdata, count, 0);
    count_gender[1] = countGender(pdata, count, 1);

    printf("Female:%d Male:%d\n", count_gender[0], count_gender[1]);

    for (i = 0; i < count; ++i) {
        free(pdata[i]);
        pdata[i] = NULL;
    }

    return 0;
}

int getCountry(char* str)
{
    if (strcmp(str, "KR") == 0) {
        return 0;
    } else if (strcmp(str, "US") == 0) {
        return 1;
    } else if (strcmp(str, "JP") == 0) {
        return 2;
    } else if (strcmp(str, "CN") == 0) {
        return 3;
    } else if (strcmp(str, "FR") == 0) {
        return 4;
    } else {
        return 5;
    }
}

void printInfo(struct st_person* p)
{
    int current_year = 2025;
    int age = current_year - p->birthyear;

    printf("%s (%s, age:%d, from ", p->name, (p->gender == 0) ? "Female" : "Male", age);

    switch (p->country) {
        case 0:
            printf("KR");
            break;
        case 1:
            printf("US");
            break;
        case 2:
            printf("JP");
            break;
        case 3:
            printf("CN");
            break;
        case 4:
            printf("FR");
            break;
        default:
            printf("--");
            break;
    }

    printf(")\n");
}

int countGender(struct st_person* data[], int size, int gender)
{
    int count = 0;
    int i;

    for (i = 0; i < size; ++i) {
        if (data[i] -> gender == gender) {
            count ++;
        }
    }

    return count;
}
