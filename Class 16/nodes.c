#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data);
void removeNodes(struct Node** head);

int main() {
    struct Node* head = NULL;

    // Add nodes to the linked list until -999 is entered
    int data;
    printf("Enter an integer (enter -999 to stop): ");
    scanf("%d", &data);
    while (data != -999) {
        addNode(&head, data);
        printf("Enter an integer (enter -999 to stop): ");
        scanf("%d", &data);
    }

    // Print the linked list
    printf("Linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Remove all nodes from the linked list
    removeNodes(&head);

    // Print the linked list after removing all nodes
    printf("Linked list after removing all nodes: NULL\n");

    return 0;
}

// Function to add a new node to the end of the linked list
void addNode(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    }
    // Otherwise, traverse to the end of the list and add the new node
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove all nodes from the linked list
void removeNodes(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;
}