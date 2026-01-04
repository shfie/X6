#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n, i, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nMenu:\n1. Display\n2. Insert\n3. Delete\n4. Search\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Array: ");
                for(i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:
                if(n == MAX) {
                    printf("Array full!\n");
                    break;
                }
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                for(i = n; i > pos; i--)
                    arr[i] = arr[i-1];
                arr[pos] = value;
                n++;
                printf("Inserted.\n");
                break;

            case 3:
                if(n == 0) {
                    printf("Array empty!\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", n-1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = pos; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
                printf("Deleted.\n");
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                for(i = 0; i < n; i++) {
                    if(arr[i] == value) {
                        printf("Found at position %d\n", i);
                        break;
                    }
                }
                if(i == n)
                    printf("Not found.\n");
                break;

            case 5:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}
