#include <stdio.h>

void display(int a[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void reverse(int a[], int n) {
    int i, temp;
    for(i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    printf("Array reversed\n");
}

void search(int a[], int n) {
    int key, i, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Element not found\n");
}

int main() {
    int a[50], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n1.Display\n2.Reverse\n3.Search\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: display(a, n); break;
            case 2: reverse(a, n); break;
            case 3: search(a, n); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
