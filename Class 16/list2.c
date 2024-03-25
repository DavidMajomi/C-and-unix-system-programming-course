#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    // Initialize nodes
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *tail = NULL;
    struct node *temp = NULL;

    // Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));


    // Assign data values
    one->data = 10;
    two->data = 20;
    three->data = 30;

    // Singly nodes
    head = one;
    one->prev = NULL;
    one->next = two;
    two->prev = one;
    two->next = three;
    three->prev = two;
    three->next = NULL;
    tail = three;

    printf("The data value in the first node is %d\n", head->data);
    printf("The data value in the second node is %d\n", head->next->data);
    printf("The data value in the third node is %d\n\n", head->next->next->data);

    temp = head;
    while (temp != NULL)
    {
        printf("The data value in the node is %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = tail;
    while (temp != NULL)
    {
        printf("The data value in the node is %d\n", temp->data);
        temp = temp->prev;
    }
    
    return 0;
}