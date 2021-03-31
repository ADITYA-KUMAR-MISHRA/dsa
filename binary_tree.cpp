#include<bits/stdc++.h>
using namespace std ; 
// class node
class node {
    public:
    node * left ;           //pointer to left node
    node * right ;          //pointer to right node
    int val ;               //value stored in the node
};
// class tree
class tree{
    private:
    node * root ;       //root node
    public:
    tree(){             //constructor to set initial node value to NULL i.e. intially the tree is empty
        root = NULL ;
    }
    void t_add(int data) ;  //function to add a node with data  to tree
    void dfp ();             //depth first  print
    void dfp (node * temp) ;  //depth first  print with overloaded function
    void bfp () ;           //breadth first print
    void bfp(node * temp) ; //overloaded breadth first print function
    bool search(int data) ;  //function to search given data into the tree
};
//function to add a node to the tree with given data
void tree :: t_add(int data){

    if(root == NULL ){                                  //if root is empty
        //allocate the root node and store the data into it
        root = (node *) malloc(sizeof(node));          
        root->val = data ;                            
        // add left and right pointers to NULL
        root->left = NULL ;                             
        root->right = NULL ;
    }
    else{
        //Created a temporary node temp set it's left and right poninters to NULL and stored the data into it
        node * temp ; 
        temp = (node *) malloc(sizeof(node));
        temp->left  = NULL ;
        temp->right = NULL ;
        temp-> val = data ;
        // temporary node temp2 to iterate through the tree to avoid loss of root node adress
        //value of temp2 is adress of root node
        node * temp2 ;
        temp2 = root ;
        while(1){
            if(data < temp2->val){              //if data to be added is smaller than the value of current node
                // if left pointer is NULL add the temporary node to left pointer and break the loop else move to left node
                if(temp2->left ==NULL){         
                    temp2->left = temp ;
                    break;
                }
                else temp2 = temp2->left ;
            }
            //if data is larger than or equal to the value of the node
            else{
                // if right pointer of the node is NULL the set it to temp node and break the loop else move to right node
                if(temp2-> right == NULL) {
                    temp2->right = temp;
                    break;
                }
                else temp2 = temp2-> right ;
            }
        }
    }
}
//recursive function to print the tree in deft first fashion and preorder mode
void tree :: dfp ( node * temp){
    if(temp  == NULL ) return ;
    else {
        printf("%d ",temp->val);
        dfp(temp->left);
        dfp(temp->right);
    }
}
//overloaded function similar to dfp without and parameters and with initial node set to root node
void tree :: dfp( ){
    if(root  == NULL ) return ;
    else {
        printf("%d ",root->val);
        dfp(root->left);
        dfp(root->right);
    }
}
//recursive function to print the tree in breadth first fashion
void tree :: bfp(){
    if(root == NULL ) return ; 
    else{
        printf("%d ", root->val);
        if(root->left != NULL) printf("%d ", root->left->val);
        if(root->right != NULL) printf("%d ", root->right->val);
        bfp(root->left);
        bfp(root->right);
    }
}
//overloaded breadth first print function
void tree :: bfp(node * temp){
    if(temp == NULL ) return ; 
    else{
        if(temp == root) printf("%d ", temp->val);
        if(temp->left != NULL) printf("%d ", temp->left->val);
        if(temp->right != NULL) printf("%d ", temp->right->val);
        bfp(temp->left);
        bfp(temp->right);
    }
}
// function to search the given data into the tree
//returns 1 if data exist in the tree and return 0 if it doesn't
bool tree :: search(int data){
    // if tree is empty return 0
    if(root == NULL )
        return 0;
    //if tree is not empty 
    else{
        //create a new temporarty node and set it to root
        node * temp ; 
        temp = root ;
        //loop until given data is found or till reaching the leaf node
        while(1){
            //if data is found then return 1 and break out of loop
            if(temp->val == data) {
                return 1 ; 
                break ;
            }
            // else if data is smaller than the value of node then check if left node doesn't exist return 0 otherwise move to left node
            else if(data < temp->val){
                if(temp -> left == NULL ){
                    return 0;
                    break;
                }
                else temp = temp->left;
            }
            /* else if data is greater than or equal to the value of the node then check if right node
            * doesn't exist then return 0 and break out of loop 
            * if left node exit then move to left node
            * */
            else {
                if(temp -> right  == NULL ){
                    return 0;
                    break;
                }
                else temp = temp -> right;
            }
        }
    }
}

int main(){
    tree t ;
    t.t_add(32);
    t.t_add(1);
    t.t_add(9);
    t.t_add(37);
    t.t_add(11);
    t.t_add(1232);
    t.t_add(8);
    t.t_add(10);
    t.t_add(31);
    t.t_add(1000);
    t.dfp();
    cout<<endl;
    t.bfp();
    string ch ; 
    cout<<"\nEnter the number to search in the given tree, press Q or q to exit\n";
    while(1){
        cin>>ch;
        if(ch == "q" || ch == "Q") break;
        else {
            cout<<t.search(stoi(ch)) <<endl;
        }
    }
}