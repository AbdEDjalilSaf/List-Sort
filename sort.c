#include <stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node* next;
};


struct Node*createNode(int data){
struct Node* newNode = malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;

return newNode;
}



void insert_node(struct Node**head,int data){
    struct Node* newnode = createNode(data);
        struct Node* t = *head;

if(*head == NULL){
    *head = newnode;
    return;
}
else
{
    while (t->next != NULL)
    {
            t = t->next;
    }  
    t->next = newnode;
}
}



void swapData(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

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



void selection(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* minNode = findMin(head);
    if (minNode != head)
        swapData(head, minNode);
    selection(head->next);
}



struct Node*merge(struct Node*left,struct Node*right){
  if(left == NULL) return right;
  if(right == NULL) return left;

struct Node*result = NULL;
if(left->data <= right->data){
    result = left;
    result->next = merge(left->next,right);
}else{
   result = right;
    result->next = merge(left,right->next); 
}
    return result;
}












void display(struct Node* head){

if(head == NULL)
return;

while(head != NULL){
printf("data is %d\n",head->data);
 head = head -> next;
}

}





int main() {
   
struct Node*head = NULL;
  
 insert_node(&head,4); 
 insert_node(&head,2);
 insert_node(&head,114); 
 insert_node(&head,232); 
 insert_node(&head,1546);
 insert_node(&head,398);
 insert_node(&head,3); 
 insert_node(&head,1); 
 
  display(head);
    
    selection(head);
    printf("after \n");
      display(head);

}   
    
    
    
    
    
    
    
