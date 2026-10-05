//Conversion of postfix to infix
#include<iostream>
#include<string.h>
using namespace std;
char stack[10][10];
int top=-1;
string pop();
void push(string  );
int main(){
    string expression;
    cout<<"Enter your postfix expression\n";
    cin>>expression;
    int l,i; 
    l=expression.size();
    for(i=0;i<l;i++){
        if(expression[i] !='+'&&expression[i] !='-'&&expression[i] !='*'&&expression[i] !='/'){
            string s(1, expression[i]);//making the string one copy of the 
            //expression[i]
            push(s);
        }
        else{
            string op1=pop();
            string op2=pop();
            char c=expression[i];

            string ch="("+op2+c+op1+")";
            push(ch);


        }
    }
    cout<<"Infix is "<<pop()<<endl;

}
void push(string s) {
    strcpy(stack[++top], s.c_str());//making array of character  
}
string pop(){
    string temp=stack[top];
    top=top-1;
    return temp;
}

