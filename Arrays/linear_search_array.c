#include <stdio.h>

int main() {
    int n, i, key;
    int a[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }

    printf("Element not found\n");
    return 0;
}
