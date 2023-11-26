#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>

typedef struct linkStruct
{
int value;
struct linkStruct* next;
}*Node;

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



void deleteBookByKey(Node*head,int value){
Node t = *head;
Node p = NULL;

if(t->next != NULL && t->value != value){
    p = t;
    t = t->next; 
}
if(t == NULL){
    return;
}
while(t != NULL){
if(t->value == value){
    p->next = t->next;
    
}
}
}




void selection_sort(Node*head){
    
    
    
    
}








void displayLibrary(Node head){

if(head == NULL){

printf("your Library is NULL");

}else{

Node  a = head;
printf("data is %d\n",a->value);
 head = head->next;
}

}





int main() {
   
    
    
    
    
}   
    
    
    
    
    
    
    
