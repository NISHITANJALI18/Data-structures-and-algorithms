#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node* insert(struct Node* root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct Node* findMin(struct Node* root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node* temp = findMin(root->right);

            // Copy inorder successor's value
            root->data = temp->data;

            // Delete inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main() {

    struct Node* root = NULL;
    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder before deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d", &deleteValue);

    // Check whether node exists
    struct Node* temp = root;
    while (temp != NULL) {
        if (deleteValue == temp->data)
            break;

        if (deleteValue < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp == NULL) {
        printf("%d is not present in the BST.\n", deleteValue);
    }
    else {
        root = deleteNode(root, deleteValue);

        printf("Node %d deleted successfully.\n", deleteValue);
        printf("Inorder after deletion: ");
        inorder(root);
    }

    return 0;
}
