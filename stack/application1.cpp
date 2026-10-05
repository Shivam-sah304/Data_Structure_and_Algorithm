// In this code we are going to take the infix from the user and 
// converting it into the postfix and then show postfix
#include<iostream>
#include <cstdlib> 
using namespace std; 
const int SIZE=50;
char stack[SIZE];
float Stack1[SIZE];
int top1=-1;
int top=-1;
void push1(float value);
float pop1();

bool isEmpty(){
    return top==-1;
     
}

int Prece(char op1, char op2) {
    int p1, p2;

    
    if (op1 == '^') p1 = 3;
    else if (op1 == '*' || op1 == '/') p1 = 2;
    else if (op1 == '+' || op1 == '-') p1 = 1;
    else p1 = -1;

    if (op2 == '^') p2 = 3;
    else if (op2 == '*' || op2 == '/') p2 = 2;
    else if (op2 == '+' || op2 == '-') p2 = 1;
    else p2 = -1;

    return (p1 >= p2) ? 1 : 0;
}
void push(char c){
    top=top+1;
    stack[top]=c;

}
char pop() {
    if (!isEmpty())
        return stack[top--];
    return '\0';
}

char peek(){
    return stack[top];
}
float result(string s1){
    int i;
    int temp;
    float operand1,operand2,l,result,oper;
    l=s1.size();
    
    for(i=0;i<l;i++){
        
        if(s1[i] !='+' && s1[i] !='-' && s1[i] != '*' && s1[i]!='/'){
            temp=s1[i]-'0';
            
            push1(temp);    
        }
        else{
            operand1=pop1();
            operand2=pop1();
            
            float temp;
            switch(s1[i]){
                case '+':
                temp=operand1+operand2;
                break;
                case '-':
                temp=operand2-operand1;
                break;
                case '*':
                temp=operand1*operand2;
                break;
                case '/':
                temp=operand2/operand1;
            }
             push1(temp);

        }
    }
    return pop1();

}
void push1(float value){
    top1=top1+1;
    Stack1[top1]=value;

}
float pop1(){
    float temp=Stack1[top1];
    top1=top1-1;
    return temp;
}
int main(){
    string expre;
    //Taking the original expression from the user  
    cout<<"Enter your Expression please\n";
    cin>>expre;
    int l=expre.size();
    // cout<<l<<endl;
    char expression[100];
    int j=0;

    for(int i=0;i<l;i++){
        // char c=expre[i];
       
 if(expre[i]=='{' || expre[i]=='('||expre[i]=='['){
    push(expre[i]);

}
else if(expre[i]=='}' || expre[i]==')' ||expre[i]==']'){
    if(expre[i] == ')'){
    while(!isEmpty() && peek() != '(')
        expression[j++] = pop();
    pop(); 
}
if(expre[i] == '}'){
    while(!isEmpty() && peek() != '{')
        expression[j++] = pop();
    pop(); 
}
if(expre[i] == ']'){
    while(!isEmpty() && peek() != '[')
        expression[j++] = pop();
    pop(); 
}
}
else if (expre[i] != '+' && expre[i] != '-' && expre[i] != '*' && expre[i] != '/') {
    expression[j++] = expre[i];
    
    
     
}
        else{
            while(! isEmpty()&& Prece(peek(),expre[i])){
                char top=pop();
                expression[j++]=top;

            }
            push(expre[i]);
        }
        

    }
    while(!isEmpty()){
        expression[j++] = pop();
    }

    expression[j] = '\0';
   
    cout<<"The Equivalent postfix is "<<expression<<endl;
// now lets use staexpre[i]k the deexpre[i]ode the postfix expression

float result1=result(expression);
cout<<"Your result is "<<result1<<endl;
}
 