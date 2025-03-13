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

int main(void) 
{
    struct st_person* one;
    char country[5];
    int gender, birthyear;

    one = (struct st_person*)malloc(sizeof(struct st_person));

    scanf("%19s %d %4s %d", one->name, &gender, country, &birthyear);

    one->gender = gender;
    one->country = getCountry(country);
    one->birthyear = birthyear;

    printInfo(one);

    free(one);
	one = NULL;
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
            printf("-");
            break;
    }
    
    printf(")\n");
}
