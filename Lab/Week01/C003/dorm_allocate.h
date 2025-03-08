#ifndef DORM_ALLOCATE_H
#define DORM_ALLOCATE_H

#define MAX_ROOMS (5)
#define MAX_OCCUPANCY (2)

typedef enum gender {
    GENDER_MALE,
    GENDER_FEMALE
} gender_t;

typedef struct student {
    char name[20];
    int room;
    gender_t gender;
} student_t;

int find_room(int room_occupants[MAX_ROOMS]);
void print_report(const student_t students[], int student_count);

#endif /* DORM_ALLOCATE_H */
