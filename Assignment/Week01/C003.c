/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

// 빈 베드가 있는 호실(인원 < 2) 중 랜덤으로 하나 선택
int findRoom(int persons[5])
{
    int available[5];
    int count = 0;
    for (int i = 0; i < 5; i++){
        if (persons[i] < 2) {
            available[count++] = i;
        }
    }
    // 빈 호실이 없으면 -1 반환
    if(count == 0) {
        return -1;
    }
    
    int randIndex = rand() % count;
    int chosen = available[randIndex];
    persons[chosen]++;
    return chosen + 1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc)
{
    int i;
    
    // 남학생 명단
    printf("남학생 명단 (%d명)\n", mc);
    for(i = 0; i < mc; i++) {
        printf("%d. %s [%d호]\n", i+1, mn[i], mr[i]);
    }
    printf("\n");
    
    // 여학생 명단
    printf("여학생 명단 (%d명)\n", wc);
    for(i = 0; i < wc; i++) {
        printf("%d. %s [%d호]\n", i+1, wn[i], wr[i]);
    }
    printf("\n");
    
    printf("호실별 배정 명단\n");
    
    // 1층(남학생): 101 ~ 105호
    for(int room = 101; room <= 105; room++) {
        printf("%d호 : ", room);
        // 해당 호실에 배정된 남학생 출력
        int first = 1;
        for(i = 0; i < mc; i++) {
            if(mr[i] == room) {
                if(!first) {
                    printf(" ");
                }
                printf("%s", mn[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    
    // 2층(여학생): 201 ~ 205호
    for(int room = 201; room <= 205; room++) {
        printf("%d호 : ", room);
        // 해당 호실에 배정된 여학생 출력
        int first = 1;
        for(i = 0; i < wc; i++) {
            if(wr[i] == room) {
                if(!first) {
                    printf(" ");
                }
                printf("%s", wn[i]);
                first = 0;
            }
        }
        printf("\n");
    }
}
