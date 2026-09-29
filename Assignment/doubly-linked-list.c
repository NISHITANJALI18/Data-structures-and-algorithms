#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;


void insertPage(char page[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted successfully.\n");
}


void moveForward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last page: %s\n", current->page);
    }
    else {
        current = current->next;
        printf("Moved forward to: %s\n", current->page);
    }
}


void moveBackward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first page: %s\n", current->page);
    }
    else {
        current = current->prev;
        printf("Moved backward to: %s\n", current->page);
    }
}


void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Page not found.\n");
        return;
    }
    if (temp == head)
        head = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else if (temp->prev != NULL)
            current = temp->prev;
        else
            current = NULL;
    }

    free(temp);

    printf("Page deleted successfully.\n");
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    printf("\nPages from first to last:\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    printf("\nPages from last to first:\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->prev != NULL)
            printf(" <-> ");

        temp = temp->prev;
    }

    printf("\n");
}
int main() {
    int choice;
    char page[50];

    while (1) {
        printf("\n===== WEB PAGE HISTORY =====\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
