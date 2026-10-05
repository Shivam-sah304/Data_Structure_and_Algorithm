#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int data;
    Node* next;

};
class Stack{
    private:
    Node* top;
    public:
    Stack(){
        top=nullptr;

    }
    void push(int value){
        Node* newNode=new Node();
        newNode->next=top;
        newNode->data=value;
        top=newNode;
        cout<<value<<" pushed into the stack"<<endl;

    }
    void pop(){
        if(top==nullptr){
            cout<<" stack underflow! stack is empty"<<endl;
            return ;
        }
        Node* temp=top;
        top=top->next; //move top to next node
        cout<<temp->data<<" Popped from the stack"<<endl;
        delete temp;

    }
    void peek(){
        if(top==NULL){
            cout<<"Underflow condition occur"<<endl;
            return;
        }
        cout<<"Your top element is "<<top->data<<endl;
    }
};
int main(){
    Stack s1;
    int i=1;
    while(i==1){
        int n;
        cout<<"Enter 1 for push,2 for pop,3 for peek and 4 for exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int p;
            cout<<"Enter the value you want to push"<<endl;
            cin>>p;
            s1.push(p);
            break;
            case 2:
            s1.pop();
            break;
            case 3:
            s1.peek();
            break;
            case 4:
            exit(0);
            break;
            default:
            cout<<"Enter the valid number "<<endl;


        }

    }
}
