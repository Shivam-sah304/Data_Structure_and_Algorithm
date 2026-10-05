// In this code we are going to implement the circular queue with the priority in ascending order
#include<iostream>
#include<cstdlib>
using namespace std;
const int SIZE=4;
int a[SIZE];
class Queue{
    private:
    int front=-1;
    int rear=-1;
    public:
    void enqueue(int value){
        if((front==0&&rear==SIZE-1)||front==rear+1 ){
            cout<<"Queue overflow condtion occur "<<endl;
            return;


        }
        else if(front==-1 && rear==-1){
            front=0;
            rear=0;
            a[rear]=value;
            cout<<value<<"is added to you queue";
            return;
            
        }
        else if(rear==SIZE-1 && front!=0){
            rear=0;

        }
        else{
            rear=rear+1;

        }
       int i=rear,j=rear;
       int temp;
      
       a[rear]=value;
       while(j!=front){
        i=(j-1+SIZE)%SIZE;
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j=i;

        }
        else{
            break;
        }

       }

       
       cout<<value<<" is added to your queue"<<endl;

    }
    void dequeue(){
        int i,j,temp;
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return;

        }
         
         
        cout<<a[front]<<" is the smallest value"<<endl;
    
    
        
        if(front==rear){
            front=-1;
            rear=-1;

        }
        else if(front==SIZE-1){
            front=0;
        }
        else{
            front=front+1;
        }
      

    
    }
};
int main(){
    int i=1,n;
    class Queue q1;
    while(i==1){
        cout<<"Enter 1 for enqueue , 2 for dequeue and 3 for exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int p;
            cout<<"enter the value you want to enter "<<endl;
            cin>>p;
            q1.enqueue(p);
            break;
            case 2:
            q1.dequeue();
            break;
            case 3:
            exit(0);
            break;

        }
    }

}