#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int value) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = new->right = NULL;
    return new;
}

// Insert a node into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a value in the BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find the smallest node (used in deletion)
struct node* findMin(struct node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversals
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free all nodes
void freeTree(struct node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;
    struct node* result;

    while (1) {
        printf("\n==== Binary Search Tree Menu ====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Delete Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d inserted successfully!\n", value);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            result = search(root, value);
            if (result != NULL)
                printf("%d found in the BST.\n", value);
            else
                printf("%d not found in the BST.\n", value);
            break;

        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            result = search(root, value); // check first
            if (result == NULL)
                printf("%d not found in the BST. Cannot delete.\n", value);
            else {
                root = deleteNode(root, value);
                printf("%d deleted successfully!\n", value);
            }
            break;

        case 7:
            printf("Exiting... freeing memory.\n");
            freeTree(root);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
