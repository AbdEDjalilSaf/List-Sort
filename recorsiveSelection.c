#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to swap data of two nodes
void swapData(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Recursive function to find the minimum node in a linked list
struct Node* findMin(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* minNode = head;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data < minNode->data)
            minNode = temp;
        temp = temp->next;
    }
    return minNode;
}

// Recursive function to perform selection sort on the linked list
void recursiveSelectionSort(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* minNode = findMin(head);
    if (minNode != head)
        swapData(head, minNode);

    recursiveSelectionSort(head->next);
}

int main() {
    struct Node* head = NULL;

    // Example data insertion
    insertAtBeginning(&head, 64);
    insertAtBeginning(&head, 25);
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 22);
    insertAtBeginning(&head, 11);

    printf("Original linked list: ");
    printList(head);

    recursiveSelectionSort(head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
