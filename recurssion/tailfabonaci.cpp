#include<iostream>
using namespace std;
int fibonacci(int);
int main(){
    int n,result,i;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<fibonacci(i)<<"\t";
    }

}
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);

}