#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50

typedef struct st_movie {
    char title[100];
    int year, genre, playtime, viewers;
    char description[255];
} MOVIE;

const char* genre_name[] = {
    "Sci-Fi", "Thriller", "Action", "Romance",
    "Musical", "Drama", "Animation", "War"
};

int loadRecords(MOVIE* list[]);
void printMovie(MOVIE* p);
void printReport(MOVIE* list[], int size);
int indexGenre(char* name);
void printGenreCount(MOVIE* list[], int size);
int maxViewers(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);

int main() 
{
    MOVIE* mlist[MAX_MOVIES];
    int count;
    int i;

    count = loadRecords(mlist);
    printf("%d records loaded.\n", count);
    
    for (i = 0; i < count; ++i) {
        printf("%d) ", i + 1);
        printMovie(mlist[i]);
    }
    
    printReport(mlist, count);
    
    for (i = 0; i < count; ++i) {
        free(mlist[i]);
        mlist[i] = NULL;
    }
    
    return 0;
}

int loadRecords(MOVIE* list[]) 
{
    int count;
    int i;

    scanf("%d", &count);
    if (count > MAX_MOVIES) {
        count = MAX_MOVIES;
    }
    
    for (i = 0; i < count; ++i) {
        getchar();
        char title[100];
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        
        char desc[255];
        fgets(desc, sizeof(desc), stdin);
        desc[strcspn(desc, "\n")] = '\0';
        
        int year, playtime, viewers;
        char genreInput[50];
        scanf("%d %s %d %d", &year, genreInput, &playtime, &viewers);
        
        list[i] = (MOVIE*)malloc(sizeof(MOVIE));
        strcpy(list[i]->title, title);
        strcpy(list[i]->description, desc);
        list[i]->year = year;
        list[i]->genre = indexGenre(genreInput);
        list[i]->playtime = playtime;
        list[i]->viewers = viewers;
    }
    
    return count;
}

void printMovie(MOVIE* p) 
{
    printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);
}

int indexGenre(char* name) 
{
    int i;

    for (i = 0; i < 8; ++i) {
        if (strcmp(name, genre_name[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void printReport(MOVIE* list[], int size) 
{
    printf("\n1. Number of movies by genre\n");
    printGenreCount(list, size);
    
    int idxLongest = maxPlaytime(list, size);
    printf("\n2. Longest\n");
    printMovie(list[idxLongest]);
    printf("%s\n", list[idxLongest]->description);
    
    int idxPopular = maxViewers(list, size);
    printf("\n3. Most popular\n");
    printMovie(list[idxPopular]);
    printf("%s\n", list[idxPopular]->description);
}

void printGenreCount(MOVIE* list[], int size) 
{
    int counts[8] = {0,};
    int i;
    
    for (i = 0; i < size; ++i) {
        int g = list[i]->genre;
        if (g >= 0 && g < 8) {
            counts[g]++;
        }
    }
    
    for (i = 0; i < 8; ++i) {
        printf("[%d] %-10s %d movies\n", i + 1, genre_name[i], counts[i]);
    }
}

int maxViewers(MOVIE* list[], int size) 
{
    int maxIndex = 0;
    int i;

    for (i = 1; i < size; ++i) {
        if (list[i]->viewers > list[maxIndex]->viewers) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int maxPlaytime(MOVIE* list[], int size) 
{
    int maxIndex = 0;
    int i;

    for (i = 1; i < size; ++i) {
        if (list[i]->playtime > list[maxIndex]->playtime) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
