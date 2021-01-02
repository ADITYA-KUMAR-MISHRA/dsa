//program to implement queue using doubly linked list
#include<bits/stdc++.h>
using namespace std;
//class for node
class node {
    public:               
    int data;
    node * prev ;
    node * next;
};
class que  {
    public:
    node * head;                    //head of queue
    node * tail ;                   //tail of queue
    que();
    void enq(int data);             //dqueue operation on queue
    void dque();                    //dqueue operation on queue
    bool q_empty();                 //check whether queue is empy or not
    void print();
} ;
//contructor to declare vairables head and tail
que::que(){
    head = (node *) malloc(sizeof(node));           //allocation of space
    tail = head;                                    //initialy head = tail
    head->next = NULL;                              //initialy next pointer = NULL
    head->prev  = NULL ;                            //initialy prev pointer = NULL
}
//enqueue operation on queue
void que :: enq(int data){
    node * temp;                                    //create a temporary node and allocate the space
    temp = (node *) malloc(sizeof(node));
    tail->next = temp;                              //previous tail's next points to new tail
    temp->data = data;                              //  store data to new tail
    temp->prev = tail;                              //prev of new tail points to previous tail
    temp->next  = NULL;                             //next of tail points to NULL
    tail = temp;                                    //assignes new tail

}
//function to dequeu the head node
void que :: dque (){
    if(head == tail) cout<<"Can't Dequeue, Queue is empty already"<<endl;
    else{
        head = head->next;                          //head moves to next node
        free(head->prev);                           //previous head is removed
        head->prev = NULL;                          //previous of head is set to NULL
    }
}

//function to print the queue
void que:: print(){
    if(q_empty()) cout<<"Queue is empty"<<endl;         //queue is empty then print the message
    else{
        node * temp;
        temp = head;
        while(temp->next != NULL){                      //iterate till tail node              
            cout<<temp->data<<" ";
            temp = temp->next;                           
        }
        cout<<temp->data<<endl;
    }
}
//checks if queue is empty
bool que::q_empty(){
    if(head == tail) return 1;
    else return 0;
}
int main(){
    que a;
    a.print();
    a.enq(40);
    a.enq(50);
    a.print();
    a.enq(90);
    a.dque();
    a.print();
}

