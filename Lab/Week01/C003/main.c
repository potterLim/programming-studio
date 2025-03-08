#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dorm_allocate.h"

#define MAX_STUDENTS (20)
#define MAX_PER_GENDER (10)

int main(void)
{
    student_t students[MAX_STUDENTS];
    int male_count = 0;
    int female_count = 0;
    int total_count;
    int room_occupancy[2][MAX_ROOMS] = { {0}, {0} };
    int menu_option;
    char input_name[20];
    gender_t student_gender;
    int floor_index;
    int room_no;
    int assigned_room;
    
    srand(time(NULL));
    
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");
    
    while (1) {
        printf("메뉴: 1. 남학생 등록 2. 여학생 등록 0. 종료 > ");
        scanf("%d", &menu_option);
        
        if (menu_option == 0) {
            break;
        } else if (menu_option == 1 || menu_option == 2) {
            if (menu_option == 1) {
                if (male_count >= MAX_PER_GENDER) {
                    printf("남학생 정원 초과입니다. 등록불가!\n");
                    continue;
                }
            } else {
                if (female_count >= MAX_PER_GENDER) {
                    printf("여학생 정원 초과입니다. 등록불가!\n");
                    continue;
                }
            }
            
            printf("학생 이름은? > ");
            scanf("%s", input_name);
            
            if (menu_option == 1) {
                student_gender = GENDER_MALE;
                floor_index = 0;
            } else {
                student_gender = GENDER_FEMALE;
                floor_index = 1;
            }
            
            room_no = find_room(room_occupancy[floor_index]);
            if (room_no == -1) {
                assert(0);
                return -1;
            }
            
            if (student_gender == GENDER_MALE) {
                assigned_room = 100 + room_no;
            } else {
                assigned_room = 200 + room_no;
            }
            
            total_count = male_count + female_count;
            strcpy(students[total_count].name, input_name);
            students[total_count].room = assigned_room;
            students[total_count].gender = student_gender;
            
            if (menu_option == 1) {
                male_count++;
            } else {
                female_count++;
            }
            
            printf("%s 학생 %d호실 배정되었습니다.\n", input_name, assigned_room);
        } else {
            printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
        }
    }
    
    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    print_report(students, male_count + female_count);
    
    return 0;
}
