#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>

typedef struct linkStruct
{
int value;
struct linkStruct* next;
}*Node;

Node head = NULL;

Node createNode(int value){
Node newNode = malloc(sizeof(struct linkStruct));
newNode->value = value;
newNode->next = NULL;

return newNode;
}



void insert_node(Node*head,int value){
    Node newnode = createNode(value);

if(*head == NULL){
    *head = newnode;
}
else
{
    Node t = *head;
    while (t->next != NULL)
    {
            t = t->next;
            t->next = newnode; 

    }  
}
}



// void deleteBookByKey(Node*head,int value){
// Node t = *head;
// Node p = NULL;

// if(t->next != NULL ){
//     p = t;
//     t = t->next; 
// }
// if(t == NULL){
//     return;
// }
// while(t != NULL){
//     p->next = t->next;
    
// }
// }




void selection_sort(Node*head){
Node temp = *head;
Node prev = NULL;
  if(temp->next != NULL){
      
  }
    
}








void display(Node head){

if(head == NULL){

printf("your Library is NULL");

}else{


printf("data is %d\n",head->value);
 head = head -> next;
}

}





int main() {
   
Node head = NULL;
  
 insert_node(&head,1); 
  display(head);
 insert_node(&head,2);  
  display(head);
 insert_node(&head,3); 
  display(head);
 insert_node(&head,4); 
  display(head);
    
    
    
}   
    
    
    
    
    
    
    
