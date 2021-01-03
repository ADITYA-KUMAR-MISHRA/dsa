//program to implement queue using circular array
#include<bits/stdc++.h>
using namespace std;
class que {
    public:
    int arr[20];                         //array of size 20
    int front;
    int rear;
    int next ;               // head and tail of queue
    //constructor to set initial values
    que(){
        // cout<<"Checkpoint 1"<<endl;
        front = 0;               //initialy head and tail both are at 0
        rear = 0;   
        next = 1;        
    }
    void nxt();
    bool q_empty();             //declaration of the function to check if queue is empty
    void enq(int data);         // declareation of enqueue 
    void dque();                // declaration of dequeue
    void print();               //declaration of print queue function
};
void que :: nxt(){
    if(rear < 19) next = rear + 1;
    else if(rear == 19) {
        next = 0;
    }
    // cout<<next<<" : Next"<<endl;
}
bool que :: q_empty(){
    if(rear = front) return 1;
    else return 0;
}
void que :: enq(int data){
    nxt();
    // cout<<"Checkpoint 2"<<endl;
    if(front == next) cout<<"Can't perform enqueue operation, Queue if full"<<endl;
    else {
        // cout<<"Checkpoint 3"<<endl;
        arr[next] = data;
        rear  = next;
    }
}
void que::print(){
    if(front == rear) cout<<"Queue is empty"<<endl;
    else{
        for(int i = front ; i<=rear ;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
void que :: dque(){
    if(front == rear) cout<<"Can't dequeue, queue is empty"<<endl;
    else{
        if(front == 19) front = 0;                  
        else front++;
    }
}
int main(){
    que a;
    a.print();
    a.dque();
    a.enq(9);
    a.enq(22);
    a.print();
    a.dque();
    a.print();

}
