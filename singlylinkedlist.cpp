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
//function to insert node in singly linked list
// n is node index
void insert(node *head, int data,int num){
    int i = 0;
    for( ;i<num;++i){                                              //reach to the node
        if(head->next == NULL) {
            cout<<"out of bounds\n";
            break;
        }
        head = head->next;
    }
    if(i == num){
        node * temp;
        temp = (node *)malloc(sizeof(node));                                    //create empty node
        temp->next = head->next;                                                //copy next to new creted node                     
        head->next = temp;                                                      
        temp->data = head->data;
        head->data = data;
    }
}
//funtion to push data at head and return adress of new head
node * pushhead(node * head, int data){
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    return temp;
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
    insert(head,1234,2);
    head =  pushhead(head,92);
    print(head);
}