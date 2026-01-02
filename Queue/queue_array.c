#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

int main() {
    int i, n;

    printf("Enter number of elements (max 5): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Overflow\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    printf("Queue elements:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
