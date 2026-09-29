#include <stdio.h>
#include <stdlib.h>
struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Student Roll Numbers: ");

    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeginning(int roll) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;

    printf("Roll number %d inserted at beginning.\n", roll);
    display();
}


void insertEnd(int roll) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Roll number %d inserted at end.\n", roll);
    display();
}

// Search for a roll number
void search(int roll) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found in the list.\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number %d not found.\n", roll);
}

// Delete a roll number
void deleteNode(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // If the first node contains the roll number
    if (head->roll == roll) {
        head = head->next;
        free(temp);

        printf("Roll number %d deleted.\n", roll);
        display();
        return;
    }

    // Search for the node
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    // Roll number not found
    if (temp == NULL) {
        printf("Roll number %d not found. Cannot delete.\n", roll);
        display();
        return;
    }

    // Delete the node
    prev->next = temp->next;
    free(temp);

    printf("Roll number %d deleted.\n", roll);
    display();
}

int main() {
    int n, i;
    int roll, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    while (1) {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
