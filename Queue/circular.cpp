#include<iostream>
using namespace std;
const int n=3;
int front=-1;
int rear=-1;
 class Queue{
    private:
    int a[n];
        
    public:
    bool Isempty(){
        return rear==-1&&front==-1;
    }
    bool Isfull(){
        return front==0&&rear==n-1;
    }
    void enqueue(int item){
        if(Isfull()||front==rear+1){
            cout<<"Overflow condition is occur"<<endl;
            return;

        }
        else if(front==-1&&rear==-1){
            rear=0;
            front=0;
        }
        else if(rear==n-1 &&front!=0){
            rear=0;
        }
        else{
            rear=rear+1;
        }
        a[rear]=item;
        cout<<item<<" is added to the queue"<<endl;

    }
    void Dequeue(){
        if(Isempty()){
            cout<<"Underflow condition is occur"<<endl;
            return;
        }
        cout<<a[front]<<" is removed from the queue"<<endl;
        if(front==rear){
            front=-1;
            rear=-1;

        }
        else if(front==n-1){
            front=0;
        }
        else{
            front=front+1;
        }

    }
    void display(){
       int i=1;
       int j=front;
       while(i==1){
        if(front==-1){
            cout<<"Dude its empty queue"<<endl;
        }
        cout<<a[j]<<"\t";
        if(j==rear){
            break;
        }
        j=(j+1)%n; //This is the best trick because when j reaches to n
        //Then its j becomes 0 so again start from 0 and print until j==rear
       }
       cout<<endl;

    }

 };
int main(){
    Queue q1;
    
    int n,i=1;
    while(i==1){
        cout<<"Enter 1 for enqueue and 2 for dequeue and 3 for display and 4 for exist"<<endl;
        cin>>n;
        if(n==1){
            int p;
            cout<<"Enter the value you want to insert"<<endl;
            cin>>p;
            q1.enqueue(p);
        }
        else if(n==2){
            q1.Dequeue();
        }
        else if(n==3){
            q1.display();
            
            
        }
        else{
            break;
        }
    }

    
}
