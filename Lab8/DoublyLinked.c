#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Added %d at the end of the list.\n", data);
}

void removeLast(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to remove.\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
    }
    printf("Removed the last element from the list.\n");
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        struct Node* current = *head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current != NULL) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
    printf("Inserted %d at position %d.\n", data, position);
}

void removeFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to remove.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    struct Node* current = *head;
    if (position == 1) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
    } else {
        int currentPosition = 1;
        while (currentPosition < position && current != NULL) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return;
        }

        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
    printf("Removed an element from position %d.\n", position);
}

void insertAfterElement(struct Node** head, int data, int element) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            struct Node* newNode = createNode(data);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            printf("Inserted %d after %d.\n", data, element);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list. Insertion failed.\n", element);
}

void insertBeforeElement(struct Node** head, int data, int element) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            struct Node* newNode = createNode(data);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head = newNode;
            }
            current->prev = newNode;
            printf("Inserted %d before %d.\n", data, element);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list. Insertion failed.\n", element);
}

void displayList(struct Node* head) {
    printf("List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("List reversed.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Add to end\n");
        printf("2. Remove from end\n");
        printf("3. Insert at position\n");
        printf("4. Remove from position\n");
        printf("5. Insert after element\n");
        printf("6. Insert before element\n");
        printf("7. Display list\n");
        printf("8. Reverse list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 2:
                removeLast(&head);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                printf("Enter the position: ");
                scanf("%d", &position);
                removeFromPosition(&head, position);
                break;

            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                insertAfterElement(&head, data, element);
                break;

            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                insertBeforeElement(&head, data, element);
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                reverseList(&head);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

