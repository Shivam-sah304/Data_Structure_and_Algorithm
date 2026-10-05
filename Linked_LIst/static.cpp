#include<iostream>
using namespace std;
const int SIZE=5;
int a[5];
class list{
    public:
    int n=0;
    void insert(int value){
        if(n>SIZE-1){
            cout<<"The list is full"<<endl;
            cout<<"Overflow condition is occur"<<endl;
            return;
        }
        a[n]=value;
        n++;
        cout<<value<<" is added to your list"<<endl;
    }
    void searching(int value){
        int i=0;
        int p=0;
        
        for(i=0;i<n;i++){
            if(a[i]==value){
                cout<<"Found : "<<value<<endl;
                p=1;
                break;
            }
        }
        if(p==0){
            cout<<"Your value is not exit inside the list"<<endl;

        }
        
    }
    
    void traverse(){
        int i=0;
        cout<<"Your value are: "<<endl;
        for(i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

};
int main(){
     list l1;
    
    int i=1;
    while(i==1){
        int n;
        cout<<"Enter 1 for insert and 2 for traverse,3 for searching and 4 for exit"<<endl;
        cin>>n;
        switch (n)
        {
        case 1:
            int p;
            cout<<"Enter your value you want to add"<<endl;
            cin>>p;
            l1.insert(p);
            break;
        case 2:
        l1.traverse();
        break;
        case 3:
        int q;
        cout<<"Enter the value search"<<endl;
        cin>>q;
        l1.searching(q);
        break;
        
        case 4:
        exit(0);
        break;
        
        default:
        cout<<"Enter the valid number "<<endl;
            break;
        }

    }
}