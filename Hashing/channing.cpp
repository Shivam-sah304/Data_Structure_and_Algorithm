//In this propgram we are going to use the chaning to remove the collision from the hash table
//Mean while our hash function is still is the mode%10

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(){
        value=-1;
        next=nullptr;
    }
};

class Hash_concept{
    private:
    //Hash table 
    Node* table[10];
//different type of the hash function
    int Hash_modulu(int key){
        int value=key%10;
        return value;

    }
    int Hash_multiplicative(int key){
        float c=0.61;
        float key1=floor(10*(key*c-floor(key*c)));
        return key1;
    }

    public:
    Hash_concept(){
        
        for(int i=0;i<10;i++){
            table[i]=nullptr;
        }
    }
    void insert(){
        int value1,p;
        cout<<"Enter the value you want to enter: "<<endl;
        cin>>value1;
        p=Hash_multiplicative(value1);
        if(table[p]==nullptr){
            Node* node1=new Node();
            node1->value=value1;
            table[p]=node1;
            cout<<"Your value "<<value1<<" is added at the hash table "<<endl;     
        }
        else{
            Node* temp;
            temp=table[p];
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            Node* newnode=new Node();
            newnode->value=value1;
            cout<<"Your value "<<value1<<" is added at the hash table "<<endl;
            temp->next=newnode;
        }
    }
void search(){
    int value1,index;
    cout<<"Enter the vlaue you want to search: "<<endl;
    cin>>value1;
    index=Hash_multiplicative(value1);
    if(table[index]==nullptr){
        cout<<"Sorry your entered value donot exit"<<endl;

    }
    else{
        Node* temp=table[index];
        do{
            if(temp->value==value1){
                cout<<"your value "<<value1<<" found"<<endl;
                return;
            }
            temp=temp->next;
        }while(temp!=nullptr);

        cout<<"your entered value is not found"<<endl;
    }
}


};
int main(){
    Hash_concept h1;
    
    int i=1;
    while(i==1){
        int c;
        cout<<"Enter 1 for insert ,2 for the searching and 3 for the exit"<<endl;
        cin>>c;
        switch(c){
            case 1:
            {
                h1.insert();
                break;
            }
            case 2:
            {
              h1.search();
              break;  
            }
            case 3:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"Enter the valid number please... "<<endl;
                break;
            }
        }

    }


}