#include<iostream>
using namespace std;
int result(int,int,int,int []);
int main(){
    int n,i;
    cout<<"How many elements you want in your array\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cout<<"Enter your elements"<<endl;
        cin>>a[i];
    }
    int low=0,high=n-1;
    int x;
    cout<<"Enter the elements you want to find"<<endl;
    cin>>x;

    int res=result(low,high,x,a);
    if(res==-1){
        cout<<"This elements do not exist in this array"<<endl;
    }
    else{
        cout<<"Your searching index is "<<res<<endl;
    }

    

}
int result(int a,int b, int x,int arr[]){
    if(a>b){
        return -1;
    }
    int mid=(a+b)/2;
    if(x==arr[mid]){
        return mid;
    }
    if(x<arr[mid]){
        return result(a,mid-1,x,arr);
    }
    else{
        return result(mid+1,b,x,arr);
    }

}