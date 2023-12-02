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

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to get the middle of the linked list for splitting
struct Node* getMiddle(struct Node* head) {
    if (head == NULL) return head;

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// Recursive function to perform merge sort on the linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* mid = getMiddle(head);
    struct Node* nextToMid = mid->next;

    mid->next = NULL;

    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(nextToMid);

    return merge(left, right);
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

    head = mergeSort(head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
