#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;  // Points to last node in circular list

// Insert at end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;  // Points to itself
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Inserted %d\n", value);
}

// Display the list
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next;  // Start from first node
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

// Delete node with given value
void deleteNode(int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next, *prev = last;

    // If list has only one node
    if (last == last->next && last->data == value) {
        free(last);
        last = NULL;
        printf("Deleted %d\n", value);
        return;
    }

    // Traversing list to find node to delete
    do {
        if (temp->data == value) {
            if (temp == last) {  // Deleting last node
                prev->next = temp->next;
                last = prev;
            } else if (temp == last->next) {  // Deleting first node
                last->next = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("Deleted %d\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    printf("Value %d not found\n", value);
}

// Search for a value
void search(int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next;
    int pos = 1;

    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);

    printf("Value %d not found\n", value);
}

int main() {
    int choice, value;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
