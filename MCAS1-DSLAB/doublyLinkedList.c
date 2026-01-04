#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int user;

    printf("Do you want   to create a doubly linked list? (1 for yes): ");
    scanf("%d",    &user);

    while (user ==     1) {
        int n;
        printf("Enter data to insert: ");
        scanf("%d", &n);

        // Create new node
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = n;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            // First node
            head = newNode;
            tail = newNode;
        } else {
            // Append at the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("%d entered successfully. \n", n);

        printf("Do you want to enter more data? (1 for yes): ");
        scanf("%d", &user);
    }

    // Print the list forward
    printf("\nDoubly  linked list in forward order:\n");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}