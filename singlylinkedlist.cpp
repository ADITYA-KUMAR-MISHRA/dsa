#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

//Function to insert node at tail give tail only and returns address of tail
node * pushback_t( node * tail, int data){
    node * temp;
    temp  = (node*)malloc(sizeof(node));        //creating and empty node
    tail->next = temp;                          //setting previous taill next to new creaded empty node
    temp->data = data;                          //storing data in empty node
    temp->next = NULL;                          //setting next of new tail node to NULL
    return temp;
}

//funition to insert node at head given head only and returns adress of tail
node * pushback_h(node * head,int data){
    while(head->next != NULL) head = head->next;                    //reach to end of list
    node * temp;
    temp = (node *)  malloc(sizeof(node));                          //create new node
    head->next = temp;                                              //change next of previous tail to adress of new node
    temp->data = data;                                              //add data to new tail
    temp->next = NULL;                                              //set new tail next ot NULL
    return temp;
}
/*************************************************************************
 * function to print the linked list 
 * @args input adress of head 
 * **********************************************************************/
void print(node * head){
    int n = 0;
    for(;head->next != NULL;n++){
        printf("Data = %d , node = %d\n",head->data,n);
        head = head->next;
    }
    printf("Data = %d , node = %d\n",head->data,n);
}
int main(){
    node * head = NULL;                             //head of the linked list
    node * tail =  NULL;                               //tail of the linked list
    head = (node*)malloc(sizeof(node));                //allocation of memory for head node 
    tail = head;                                        //initialy head == tail
    tail = pushback_t(tail,4);
    tail = pushback_t(tail,9);
    tail = pushback_h(head,69);
    tail = pushback_t(tail,50);
    print(head);

}