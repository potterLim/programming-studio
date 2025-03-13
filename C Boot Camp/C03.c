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
int countGender(struct st_person* pdata[], int count, int country, int gender);
double averageAge(struct st_person* pdata[], int count, int country);

int main(void)
{
    struct st_person* pdata[20];
    char country[5];
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

    for (i = 0; i <= 5; ++i) {
        int female_count = countGender(pdata, count, i, 0);
        int male_count = countGender(pdata, count, i, 1);
        double avg_age = averageAge(pdata, count, i);

        if (female_count > 0 || male_count > 0) {
            printf("[");
            switch (i) {
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
            printf("] Female:%d Male:%d average age:%.1f\n", female_count, male_count, avg_age);
        }
    }

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

int countGender(struct st_person* pdata[], int count, int country, int gender)
{
    int i;
    int gender_count = 0;
    for (i = 0; i < count; ++i) {
        if (pdata[i]->country == country && pdata[i]->gender == gender) {
            ++gender_count;
        }
    }
    return gender_count;
}

double averageAge(struct st_person* pdata[], int count, int country)
{
    int i;
    int total_age = 0;
    int num_people = 0;
    int current_year = 2025;

    for (i = 0; i < count; ++i) {
        if (pdata[i]->country == country) {
            total_age += (current_year - pdata[i]->birthyear);
            ++num_people;
        }
    }

    return (num_people > 0) ? (double)total_age / num_people : 0.0;
}
