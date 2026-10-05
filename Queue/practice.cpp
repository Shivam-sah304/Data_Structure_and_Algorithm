#include<iostream>
using namespace std;
const int SIZE=3 ;
int queue[SIZE];
int rear=-1;
int front=-1; 

class Queue{
    public:

    bool isempty(){
        return rear==-1;
    }
    bool isFull(){ 
        return rear==SIZE-1;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"The overflow condition occur"<<endl;
            return;
        }
        if(isempty()){
            front=rear=0;
        }
        else{
            rear=rear+1;

        }
       
        
        queue[rear]=value;
        cout<<value<<" is added into the queue"<<endl;

        
    }
    void dequeue(){
        if(isempty() || front>rear){
            cout<<"Underflow condition is occur"<<endl;
            return;
        }
        else{
            cout<<queue[front]<<" is removed from the queue"<<endl;
            front=front+1;
        }
    }
    void display(){
        int i;
        cout<<"The values are"<<endl;
        for(i=front;i<=rear;i++){
            cout<<queue[i]<<"\t";

        }
    }
    

};

int main(){
    Queue q1;
    
    int n,i=1;
    while(i==1){
        cout<<"Enter 1 for enqueue and 2 for dequeue,3 for display and 4 for exit"<<endl;
        cin>>n;
        if(n==1){
            int p;
            cout<<"Enter the value you want to insert"<<endl;
            cin>>p;
            q1.enqueue(p);
        }
        else if(n==2){
            q1.dequeue();
        }
        else if(n==3){
            q1.display();
            break;
        }
        else{
            break;
        }
    }

    
}
