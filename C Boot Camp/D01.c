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

void printMovie(MOVIE* p);
int indexGenre(char* name);

int main() 
{
    MOVIE* list[MAX_MOVIES];
    int count;
    char title[100], desc[255], genre[50];
    int year, playtime, viewers;
    
    scanf("%d", &count);
    if (count > MAX_MOVIES) {
        count = MAX_MOVIES;
    }
    
    for (int i = 0; i < count; i++) {
        getchar();
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        
        fgets(desc, sizeof(desc), stdin);
        desc[strcspn(desc, "\n")] = '\0';
        
        scanf("%d %s %d %d", &year, genre, &playtime, &viewers);
        
        list[i] = (MOVIE*)malloc(sizeof(MOVIE));
        
        strcpy(list[i]->title, title);
        strcpy(list[i]->description, desc);
        list[i]->year = year;
        list[i]->genre = indexGenre(genre);
        list[i]->playtime = playtime;
        list[i]->viewers = viewers;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d) ", i + 1);
        printMovie(list[i]);
        free(list[i]);
        list[i] = NULL;
    }
    
    return 0;
}

void printMovie(MOVIE* p) 
{
    printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);
}

int indexGenre(char* name) 
{
    for (int i = 0; i < 8; i++) {
        if (strcmp(name, genre_name[i]) == 0) {
            return i;
        }
    }
    return -1;
}