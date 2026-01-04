#include <stdio.h>

// Universal set has 4 elements: {a, b, c, d}
#define UNIVERSE_SIZE 4

// Function to print a set from a bit string
void printSet(int set) {
    char universe[] = {'a', 'b', 'c', 'd'};
    printf("{ ");
    for (int i = 0; i < UNIVERSE_SIZE; i++) {
        if (set & (1 << (UNIVERSE_SIZE - 1 - i))) {
            printf("%c ", universe[i]);
        }
    }
    printf("}\n");
}

int main() {
    // Example sets:
    // A = {a, c} => 1010 => 10 in decimal
    // B = {b, c, d} => 0111 => 7 in decimal

    int A = 0b1010;  // Set A
    int B = 0b0111;  // Set B

    printf("Set A: ");
    printSet(A);

    printf("Set B: ");
    printSet(B);

    // Union: A | B
    int unionSet = A | B;
    printf("A | B (Union): ");
    printSet(unionSet);

    // Intersection: A & B
    int intersectionSet = A & B;
    printf("A & B (Intersection): ");
    printSet(intersectionSet);

    // Difference: A - B = A & ~B
    int differenceSet = A & ~B;
    printf("A - B (Difference): ");
    printSet(differenceSet);

    // Symmetric Difference: A ^ B
    int symDiffSet = A ^ B;
    printf("A ^ B (Symmetric Difference): ");
    printSet(symDiffSet);

    // Complement of A (with respect to universal set)
    int mask = (1 << UNIVERSE_SIZE) - 1;  // Mask to limit to universe size
    int complementA = (~A) & mask;
    printf("~A (Complement): ");
    printSet(complementA);

    return 0;
}
