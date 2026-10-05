#include<iostream>
using namespace std;
int fact(int ,int);
int main(){
    int n,result;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    result=fact(n,1);
    cout<<"The result is "<<result<<endl;
}
int fact(int n,int result=1){
    if(n==1)
        return result;
    
    
    return fact(n-1,result*n);
    

}