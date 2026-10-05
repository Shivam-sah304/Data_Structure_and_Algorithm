#include<iostream>
using namespace std;
void towers(int ,char,char,char);
int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    towers(n,'A','C','B');
}
void towers(int n,char frompeg,char topeg,char auxpeg){
    if(n==1){
        cout<<"Move disk 1 from peg "<<frompeg<<"to peg "<<topeg<<endl;
        return;
    }
    towers(n-1,frompeg,auxpeg,topeg);
    cout<<"move disk "<<n<<"from peg "<<frompeg<<"to peg "<<topeg<<endl;
    towers(n-1,auxpeg,topeg,frompeg);
}
