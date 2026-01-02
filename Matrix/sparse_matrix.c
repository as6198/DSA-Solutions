#include <stdio.h>

int main() {
    int a[10][10];
    int r, c, i, j, count = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != 0)
                count++;

    if (count > (r * c) / 2) {
        printf("Not a sparse matrix\n");
        return 0;
    }

    printf("Sparse matrix representation (row col value):\n");
    printf("Row Col Value\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0)
                printf("%d   %d   %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}
