#include<bits/stdc++.h>
using namespace std;
class stk{
    public:
    int maximum = 100;
    int stk[100];                 //stack
    int node  = -1;
    void pop();
    void push(int data);
    bool stk_empty();
    void print();

};
void stk::pop(){
    if(node <0) cout<<"Can't pop, Empty stack"<<endl;
    else{
        node--;
    }
}
void stk::push(int data){
    if(node>= maximum) cout<<"Stack overflow"<<endl;
    else{
        node++;
        stk[node] =data;
    }
}
bool stk::stk_empty(){
    if(node <0)
        return true;
        else
        {
            return false;
        }
        
}
void stk::print(){
    if(node <0) cout<<"Empty stack"<<endl;
    else{
        for(int i = 0;i<=node;i++){
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    stk a;
    a.print();
    a.pop();
    a.push(99);
    a.push(12);
    a.push(21);
    a.print();
    a.pop();
    a.print();
    a.stk_empty() ? cout<<"Empty"<<endl : cout<<"Not empty"<<endl;

}