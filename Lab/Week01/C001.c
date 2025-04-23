#include <assert.h>
#include <stdio.h>

int main(void)
{
    int size;
    int left_space;
    int right_space;
    int i;
    int j;

    scanf("%d", &size);
    assert(size >= 0);

    /* Upper part of the trophy (V-shape) */
    for (i = 0; i < size; ++i) {
        for (j = 0; j < 2 * size; ++j) {
            if (j == i || j == 2 * size - (i + 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    /* Middle part of the trophy (horizontal bar) */
    for (i = 0; i < 2 * size; ++i) {
        left_space = i - (size + 1);
        right_space = 2 * size - (i - size);

        for (j = 0; j < 2 * size; ++j) {
            if (i < size) {
                printf("*");
            } else {
                if (j > left_space && j < right_space) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    /* Lower part of the trophy (stand) */
    for (i = 0; i < 2 * size; ++i) {
        printf("*");
    }

    return 0;
}
