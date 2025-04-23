#include <assert.h>
#include <stdio.h>

#define TOTAL_FLOORS         (4)
#define ROOMS_PER_FLOOR      (3)
#define ROOM_CAPACITY        (4)

#define COUNT_MEN_FLOORS     (2)
#define COUNT_WOMEN_FLOORS   (TOTAL_FLOORS - COUNT_MEN_FLOORS)

#define TOTAL_MEN_CAPACITY   (COUNT_MEN_FLOORS * ROOMS_PER_FLOOR * ROOM_CAPACITY)
#define TOTAL_WOMEN_CAPACITY (COUNT_WOMEN_FLOORS * ROOMS_PER_FLOOR * ROOM_CAPACITY)
#define TOTAL_DORM_CAPACITY  (TOTAL_MEN_CAPACITY + TOTAL_WOMEN_CAPACITY)

#define FIRST_MEN_FLOOR      (0)
#define FIRST_WOMEN_FLOOR    (COUNT_MEN_FLOORS)

enum person_type {
    PERSON_TYPE_MEN,
    PERSON_TYPE_WOMEN,
    PERSON_TYPE_TOTAL,
    PERSON_TYPE_COUNT
};

int main(void)
{
    int room_occupants[TOTAL_FLOORS][ROOMS_PER_FLOOR];
    int person_count_by_type[PERSON_TYPE_COUNT] = { 0, };
    float occupancy_rate_by_type[PERSON_TYPE_COUNT];
    int i;
    int j;

    for (i = 0; i < TOTAL_FLOORS; ++i) {
        if (i == FIRST_MEN_FLOOR) {
            printf("Check room (Men)\n");
        } else if (i == FIRST_WOMEN_FLOOR) {
            printf("Check room (Women)\n");
        }
        for (j = 0; j < ROOMS_PER_FLOOR; ++j) {
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &room_occupants[i][j]);
            assert(room_occupants[i][j] >= 0);

            if (i < COUNT_MEN_FLOORS) {
                person_count_by_type[PERSON_TYPE_MEN] += room_occupants[i][j];
            } else {
                person_count_by_type[PERSON_TYPE_WOMEN] += room_occupants[i][j];
            }
        }
    }

    person_count_by_type[PERSON_TYPE_TOTAL] = person_count_by_type[PERSON_TYPE_MEN] + person_count_by_type[PERSON_TYPE_WOMEN];

    occupancy_rate_by_type[PERSON_TYPE_MEN] = person_count_by_type[PERSON_TYPE_MEN] / (float)TOTAL_MEN_CAPACITY * 100;
    occupancy_rate_by_type[PERSON_TYPE_WOMEN] = person_count_by_type[PERSON_TYPE_WOMEN] / (float)TOTAL_WOMEN_CAPACITY * 100;
    occupancy_rate_by_type[PERSON_TYPE_TOTAL] = person_count_by_type[PERSON_TYPE_TOTAL] / (float)TOTAL_DORM_CAPACITY * 100;

    printf("Check Result\n");
    printf("Men: %d/%d (%.1f%%)\n", person_count_by_type[PERSON_TYPE_MEN], TOTAL_MEN_CAPACITY, occupancy_rate_by_type[PERSON_TYPE_MEN]);
    printf("Women: %d/%d (%.1f%%)\n", person_count_by_type[PERSON_TYPE_WOMEN], TOTAL_WOMEN_CAPACITY, occupancy_rate_by_type[PERSON_TYPE_WOMEN]);
    printf("Total: %d/%d (%.1f%%)\n", person_count_by_type[PERSON_TYPE_TOTAL], TOTAL_DORM_CAPACITY, occupancy_rate_by_type[PERSON_TYPE_TOTAL]);

    return 0;
}
