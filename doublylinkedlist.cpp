#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * prev;
    node * next;
};
//function to push the node at tail 
void pushback(node ** tail, int data){
    // cout<<"Adress of previous tail"<<*tail<<endl;
    node * temp;                            //creating new node
    temp  = (node*)malloc(sizeof(node));
    (*tail)->next = temp;                   //next of previous tail points to new tail
    temp->data = data;                      //store data in new tail node
    temp->next = NULL;                      //new tail's next point to null
    temp->prev = *tail;                     //new tail's prev points ot previous tail
    (*tail) = temp;                         //replacing old tail with new one
    // cout<<"Adress of new tail"<<*tail<<endl;
}
//function to insert new head node 
void pushhead(node ** head , int data){
    node * temp;
    temp = (node *)malloc(sizeof(temp));      //creating new node
    temp->data = data;                          //storing data to newly created node
    temp->next = *head;                         //next of new head points to previous head
    temp->prev = NULL;                          //prev of new head points to NULL
    (*head)->prev = temp;                       //setting prev of previous head to adress of new created head
    (*head) = temp;                             //Replacing old head with new one

}
//function to delete tail of the list
void poptail(node ** tail){
    if((*tail)->prev == NULL) cout<<"List is already empty"<<endl;     //if list is already empty then prints this message
    else{                                                           //else            
        (*tail) = (*tail)->prev;                                    // settig tail to previous tail
        free((*tail)->next);                                        //free the space
        (*tail)->next =NULL;                                        //setting new tail next to NULL
    }
}
//function to pop head of the list
void pophead(node** head){
    if((*head)->next == NULL) cout<<"List already empty"<<endl;     //if list already empty then prints the message
    else{
        *head = (*head)->next ;                                     //setting head node to next node
        free((*head)->prev);                                        //free the space of the previous head node
        (*head)->prev = NULL ;                                      //prev of new head points to NULL
    }
}
//function to print elements of the list
void print(node * head){
    if(head->next == NULL) cout<<"Empty list"<<endl;
    else{
        while(head->next != NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<head->data<<endl;
    }
}
//function to insert a new node
void insert(node ** head,int n, int data){
    if(n == 0) pushhead(head,data);                         //if n = 0 then call pusheead function 
    else{
        // cout<<"Entered";
        node * temp;                                        //creating new temmporary node node
        temp = *head;
        // cout<<temp<<" "<<*head;
        int i;
        for(i = 0;i<n-1;i++){                             //reach to the n-1th node
            // cout<<"Entered loop";
            if(temp->next == NULL) {
                cout<<"Can't Insert, Out of bounds"<<endl; 
                break;
            }
            temp = temp->next;
        }
        if(i == n-1){
            node * t;                                   //create new node
            t = (node *)malloc(sizeof(node));           //allocate space to new node
            t->data = data;                             //store data to new node 
            t->next = temp->next;                       //new node points to next node
            t->prev = temp;                             //prev points to previous node
            temp->next = t ;                            //previous node points to new created node
            (t->next)->prev = t;                        //prev of next node points to new node      
            
        }

    }
}
//function to remove the node in between
void remove(node ** head, int n){
    if(n == 0) pophead(head);                           //if n == 0 then calls the function pophead
    else{
        node * t;                                       //create a temporary node
        t = *head;
        int i;
        for(i = 0;i<n;i++){                             //reach at nth node
            if(t->next == NULL){
                cout<<"Can't Remove, Out of bounds"<<endl;            //if reach at tail then print out of bounds and break from the loop
                break;
            }
            t = t->next;                                
        }
        if(i == n){
            t = t->prev;                                //move back to previous node
            t->next = t->next->next;                    //next of node points to next of next
            free(t->next);                              //free the space of removed node
        }
    }
}
int main(){
    node * head = NULL;                         //initially both head and tail pointers are set to null
    node * tail = NULL;
    head = (node *)malloc(sizeof(node));
    tail = head;
    head->next = NULL;
    head->prev  = NULL;
    pushback(&tail, 0);
    pushback(&tail,1);
    pophead(&head);
    pushhead(&head, 2);
    print(head);
    pushhead(&head,3);
    poptail(&tail);
    pushback(&tail,4);
    insert(&head,3,5);
    remove(&head,2);
    print(head);
}