//We hashing we want to reduce the time complexity of the searching by using the hash function
//Hash table is the table in which we store our values
//function function take our key of the information and give the index of the hash table
//we efficient hash function and hash table our searching time complexity becomes O(1)
//which is the ideal situation generally we have more than that 

//In this code we are going to use the hash function as the mod%10

#include<iostream>
#include<cstdlib>
using namespace std;
int Hash(int key);
int main(){
    int a[10],i=1;
    for(int j=0;j<10;j++){
        a[j]=-1;
    }
    int t;
    while(i==1){
    cout<<"Enter 1 for insert the value in the hash table,2 for the searching and 3 for exit"<<endl;
    cin>>t;
    switch (t)
    {
    case 1:{
        int p;
        cout<<"Enter the value you want to store"<<endl;
        cin>>p;
        int q=Hash(p);
        if(a[q]!=-1){
            cout<<"collision occur "<<endl;
            break;
        }
        else{
        a[q]=p;
        cout<<"Your value "<<p<<" is added "<<endl;
        }
        break;
    }
    case 2:{
    int k;
    cout<<"Enter the value you want to search "<<endl;
    cin>>k;
    int r=Hash(k);
    if(a[r]!=-1){
        cout<<"Your value is "<<a[r]<<endl;
    }
    else{
        cout<<"sorry you are not entered anything at that index"<<endl;

    }
    break;
}
    case 3:{
    exit(0);
    break;
    } 
    default:{
    cout<<"Enter the valid number please!!"<<endl;
        break;
    }
    }
}

}
int Hash(int key){
    int value=key%10;
    return value;
}

