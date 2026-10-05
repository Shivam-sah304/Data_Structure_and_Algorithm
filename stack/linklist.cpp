// Stack using the link list 
#include<iostream>
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
        top=top ->next; //move top to next node
        cout<<temp->data<<" Popped from the stack"<<endl;
        delete temp;

    }
};
int main(){
    Stack s1;
    s1.push(34);
    s1.push(54);
    s1.pop();
    s1.pop();
    s1.pop();
    Stack s2;
    s2.push(55);
    s2.push(86);
    s2.push(90);
    s2.pop();
    s2.pop();
}
