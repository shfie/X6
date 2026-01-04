#include <stdio.h>

void Union(int set1[], int n, int set2[], int m) {
    int i, j;
    printf("Union: { ");
    
    // Print all elements of set1
    for (i = 0; i < n; i++) {
        printf("%d ", set1[i]);
    }

    // Print elements of set2 that are not in set1
    for (i = 0; i < m; i++) {
        int found = 0;
        for (j = 0; j < n; j++) {
            if (set2[i] == set1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", set2[i]);
        }
    }
    printf("}\n");
}

void Intersection(int set1[], int n, int set2[], int m) {
    int i, j;
    printf("Intersection: { ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (set1[i] == set2[j]) {
                printf("%d ", set1[i]);
                break;
            }
        }
    }
    printf("}\n");
}

void Difference(int set1[], int n, int set2[], int m) {
    int i, j;
    printf("Difference (A - B): { ");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < m; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", set1[i]);
        }
    }
    printf("}\n");
}

int main() {
    int n, m, i;
    int set1[100], set2[100];

    printf("ENTER NO OF ELEMENTS IN FIRST SET: ");
    scanf("%d", &n);
    
    printf("ENTER ELEMENTS:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set1[i]);
    }

    printf("ENTER NO OF ELEMENTS IN SECOND SET: ");
    scanf("%d", &m);
    
    printf("ENTER ELEMENTS:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &set2[i]);
    }

    int choice;
    do {
        printf("\nSET OPERATIONS\n");
        printf("1. UNION\n");
        printf("2. INTERSECTION\n");
        printf("3. DIFFERENCE (A - B)\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Union(set1, n, set2, m);
                break;
            case 2:
                Intersection(set1, n, set2, m);
                break;
            case 3:
                Difference(set1, n, set2, m);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
