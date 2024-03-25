#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, struct Node** tail, int data);
void printList(struct Node** head, struct Node** tail);
void removeNodes(struct Node** head, struct Node** tail);

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Add nodes to the linked list until -999 is entered
    int data;
    printf("Enter an integer (enter -999 to stop): ");
    scanf("%d", &data);
    while (data != -999) {
        addNode(&head, &tail, data);
        printf("Enter an integer (enter -999 to stop): ");
        scanf("%d", &data);
    }

    // Print the linked list
    printList(&head, &tail);

    // Remove all nodes from the linked list
    removeNodes(&head, &tail);

    // Print the linked list after removing all nodes
    printf("Linked list after removing all nodes: NULL\n");

    return 0;
}

// Function to add a new node to the end of the linked list
void addNode(struct Node** head, struct Node** tail, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head and tail
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }
    // Otherwise, make the current tail point to the new node and update the tail
    else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to print the linked list
void printList(struct Node** head, struct Node** tail) {
    printf("Linked list: ");
    struct Node* temp = *head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to remove all nodes from the linked list
void removeNodes(struct Node** head, struct Node** tail) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;
    *tail = NULL;
}