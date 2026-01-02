#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void countNodes() {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", count);
}

int main() {
    int choice;
    do {
        printf("\n--- COUNT NODES ---\n");
        printf("1. Insert\n");
        printf("2. Count nodes\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: countNodes(); break;
            case 3: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
