#include<iostream>
using namespace std;
int sum(int ,int);
int main(){
    int n,result;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    result=sum(n,1);
    cout<<"The total sum is "<<result;
}
int sum(int n,int result=1){
    if(n<=1){
        return result;
    }
    return sum(n-1,result+n); 


}