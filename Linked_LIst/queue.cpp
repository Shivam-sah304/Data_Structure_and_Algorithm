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
    Node *tail;
    public:
    Stack(){
        top=nullptr;
        tail=nullptr;

    }
    void enqueue(int value){
        if(top==NULL){
        Node* newNode=new Node();
        newNode->next=top;
        newNode->data=value;
        top=newNode;
        cout<<value<<" added into the queue"<<endl;
        tail=top;
        return;  
        }
        Node* newNode=new Node();
        newNode->next=NULL;
        newNode->data=value;
        tail->next=newNode;
        tail=newNode;
        cout<<value<<" added into the queue"<<endl;

    }
    void dequeue(){
        if(top==nullptr){
            cout<<" queue underflow! queue is empty"<<endl;
            return ;
        }
        Node* temp=top;
        top=top->next; //move top to next node
        cout<<temp->data<<" remove from the queue"<<endl;
        delete temp;

    }
    
};
int main(){
    Stack q1;
    int i=1;
    while(i==1){
        int n;
        cout<<"Enter 1 for enqueue,2 for dequeue and 3 for exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int p;
            cout<<"Enter the value you want to push"<<endl;
            cin>>p;
            q1.enqueue(p);
            break;
            case 2:
            q1.dequeue();
            break;
            
            case 3:
            exit(0);
            break;
            default:
            cout<<"Enter the valid number "<<endl;


        }

    }
}
