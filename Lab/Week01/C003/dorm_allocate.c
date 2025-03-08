#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm_allocate.h"

int find_room(int room_occupants[MAX_ROOMS])
{
    int available_rooms[MAX_ROOMS];
    int available_count;
    int i;
    int random_index;
    int selected_index;

    available_count = 0;
    for (i = 0; i < MAX_ROOMS; ++i) {
        if (room_occupants[i] < MAX_OCCUPANCY) {
            available_rooms[available_count] = i;
            available_count++;
        }
    }
    if (available_count == 0) {
        assert(0);
        return -1;
    }
    random_index = rand() % available_count;
    selected_index = available_rooms[random_index];
    room_occupants[selected_index]++;
    return selected_index + 1;
}

void print_report(const student_t students[], int student_count)
{
    int i;
    int j;
    int male_count;
    int female_count;
    int count;
    int room_number;
    int printed;

    male_count = 0;
    female_count = 0;
    for (i = 0; i < student_count; ++i) {
        if (students[i].gender == GENDER_MALE) {
            male_count++;
        } else {
            female_count++;
        }
    }

    printf("남학생 명단 (%d명)\n", male_count);
    count = 1;
    for (i = 0; i < student_count; ++i) {
        if (students[i].gender == GENDER_MALE) {
            printf("%d. %s [%d호]\n", count, students[i].name, students[i].room);
            count++;
        }
    }

    printf("\n여학생 명단 (%d명)\n", female_count);
    count = 1;
    for (i = 0; i < student_count; ++i) {
        if (students[i].gender == GENDER_FEMALE) {
            printf("%d. %s [%d호]\n", count, students[i].name, students[i].room);
            count++;
        }
    }
    
    printf("\n호실별 배정 명단\n");
    for (i = 1; i <= MAX_ROOMS; ++i) {
        room_number = 100 + i;
        printf("%d : ", room_number);
        printed = 0;
        for (j = 0; j < student_count; ++j) {
            if ((students[j].gender == GENDER_MALE) &&
                (students[j].room == room_number)) {
                if (printed) {
                    printf(" ");
                }
                printf("%s", students[j].name);
                printed = 1;
            }
        }
        printf("\n");
    }

    for (i = 1; i <= MAX_ROOMS; ++i) {
        room_number = 200 + i;
        printf("%d : ", room_number);
        printed = 0;
        for (j = 0; j < student_count; ++j) {
            if ((students[j].gender == GENDER_FEMALE) &&
                (students[j].room == room_number)) {
                if (printed) {
                    printf(" ");
                }
                printf("%s", students[j].name);
                printed = 1;
            }
        }
        printf("\n");
    }
}
