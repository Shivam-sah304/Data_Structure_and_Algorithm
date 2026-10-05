#include<iostream>
using namespace std;
struct Node{
    int coeffi;
    int exponent;
    Node *next;
};
class application{
    private:
    Node *head;
    Node *tail;
    
    public:
    application(){
        head=NULL;
        tail=NULL;
        ;

    }
    void insert(int coff,int expo){
        if(head==NULL){
            head=new Node();
            head->coeffi=coff;
            head->exponent=expo;
            head->next=NULL;
            cout<<"Your value is added in the polynomial"<<endl;
            tail=head;
            return;

        }
        Node *newnode=new Node();
        newnode->coeffi=coff;
        newnode->exponent=expo;
        cout<<"Your value is added in the polynomial"<<endl;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;

    }

    void appendNode(Node* &head, Node* &tail, int coeff, int exp) { //This function helps in addition
    
    Node* newNode = new Node();
    newNode->coeffi = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void appendNode1(Node* &head, Node* &tail, int coeff1,int coeff2, int exp1,int expo2) { 
  //This function helps in multplication  
    Node* newNode = new Node();
    newNode->coeffi = coeff1*coeff2;
    newNode->exponent = exp1+expo2;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
    void addsum(application a1,application a2){   
        Node *temp1;
        Node *temp2;
    
        temp1=a1.head;
        if(temp1==NULL){
            cout<<"You are not entered anything in your first polynomial"<<endl;
            return ;
        }
        temp2=a2.head;
        if(temp2==NULL){
            cout<<"You are not entered anything in your second polynomial"<<endl;
            return;
        }
        Node *temp3=NULL;
        Node *temp4=NULL;
        while(temp1!=NULL && temp2!=NULL){
         if(temp1->exponent>temp2->exponent){
            appendNode(temp3,temp4,temp1->coeffi,temp1->exponent);
            temp1=temp1->next;
         }

         else if(temp1->exponent<temp2->exponent){
            appendNode(temp3,temp4,temp2->coeffi,temp2->exponent);
            temp2=temp2->next;
         }

         else{
            int result;
            result=temp1->coeffi+temp2->coeffi;
            if(result!=0){
            appendNode(temp3,temp4,result,temp1->exponent);
            }
            temp1=temp1->next;
            temp2=temp2->next;
         }
        }
        while (temp1 != NULL) {
        appendNode(temp3, temp4, temp1->coeffi, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        appendNode(temp3, temp4, temp2->coeffi, temp2->exponent);
        temp2 = temp2->next;
    }

    this->head=temp3;
    this->tail=temp4;       
    }
    void Multiplication(application a1,application a2){
        Node *temp1;
        Node *temp2;
        temp1=a1.head;
        if(temp1==NULL){
            cout<<"You are not entered anything in your first polynomial"<<endl;
            return ;
        }
        temp2=a2.head;
        if(temp2==NULL){
            cout<<"You are not entered anything in your second polynomial"<<endl;
            return;
        }
        Node *temp3=NULL;
        Node *temp4=NULL;
        
        while(temp1!=NULL){
            while(temp2!=NULL){
                appendNode1(temp3,temp4,temp1->coeffi,temp2->coeffi,temp1->exponent,temp2->exponent);
                temp2=temp2->next;
            }
            temp2=a2.head;
            temp1=temp1->next;
        }
    this->head=temp3;
    this->tail=temp4;       
    }
    void display(){
        Node *temp;
        temp=head;
        
        bool firstterm=true;
        while(temp!=NULL){
            
            if(temp->coeffi!=0){
                if(!firstterm){
                cout<<"+";
            }
                cout<<temp->coeffi<<"*x^"<<temp->exponent;
                firstterm=false;
            
            
            }
            temp=temp->next;
        
        }
        cout<<endl;
    }
};
int main(){
    application c1,c2,c3,c4;
    int n,i,m;
    cout<<"How many term in your first polynomial"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        int coff,expo;
        cout<<"Enter the coeff and expo"<<endl;
        cin>>coff>>expo;
        c1.insert(coff,expo);
    }

    cout<<"How many term in your second polynomial"<<endl;
    cin>>m;
    for(i=0;i<m;i++){
        int coff,expo;
        cout<<"Enter the coeff and expo"<<endl;
        cin>>coff>>expo;
        c2.insert(coff,expo);
    }
    c3.addsum(c1,c2);
    cout<<"The addition of your two polynomial is: ";
    c3.display();
    
    c4.Multiplication(c1,c2);
    cout<<"The multiplication of two polynomial is: ";
    c4.display();

}