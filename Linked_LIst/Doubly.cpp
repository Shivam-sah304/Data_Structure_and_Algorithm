#include <iostream>
#include<cstdlib>
using namespace std;
struct Node
{
    int item;
    Node *prev;
    Node *next;
};
class Linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void inserttail(int value)
    {
        if (head == NULL)
        {
            head = new Node();
            head->item = value;
            cout << value << " is added at the end of the list" << endl;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
            return;
        }
        Node *newnode = new Node();
        newnode->item = value;
        cout << value << " is added at the end of the list" << endl;
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    void inserthead(int value)
    {

        if (head == NULL)
        {
            head = new Node();
            head->item = value;
            cout << value << " is added at the begning of the list" << endl;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
            return;
        }
        Node *newnode = new Node();
        newnode->item = value;
        cout << value << " is added at the begning of the list" << endl;
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
    void insertindex(int value, int index)
    {
        if (index==0)
        {
            cout << "adding at first" << endl;
            inserthead(value);
            return;
        }
        if (head == NULL)
        {
            cout << "adding at first" << endl;
            inserthead(value);
            return;
        }
        
        if (index < 0)
        {
            cout << "Enter the valid index" << endl;
        }
        int i = 0;
        Node *temp;
        temp = head;
        while (i < index - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            cout << "Index is out of bound " << endl;
            cout << "adding at the end" << endl;
            inserttail(value);
        }
        Node *newnode = new Node();
        newnode->item = value;
        cout <<value<<" is addded at the index "<<i+1<< endl;
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void deltail()
    {
        if (head == NULL)
        {
            cout << "Underflow condition is exit" << endl;
            return;
        }
        if (tail->prev == NULL)
        {
            cout << "only one item is exit" << endl;
            cout << tail->item << "is deleted"<<endl;
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *newnode = new Node();
        newnode = tail;
        cout << newnode->item << "is deleted form the end" << endl;
        tail = newnode->prev;

        tail->next = NULL;

        delete newnode;
    }
    void delhead()
    {
        if (head == NULL)
        {
            cout << "Underflow condition is exit" << endl;
            return;
        }
        if (head->next == NULL)
        {
            cout << "only one item is exit" << endl;
            cout << head->item << "is deleted"<<endl;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

       
        Node *newnode = new Node();
        newnode = head;
        cout << newnode->item << "is deleted form the head" << endl;
        
        head= newnode->next;
        head->prev=NULL;

        

        delete newnode;
    }



    void delindex(int index)
    
    {
        if(head==NULL){
            cout<<"Underflow exist"<<endl;
        }
        if (index == 0)
        {
           
            delhead();
            return;
        }
        if (index < 0)
        {
            cout << "Enter the valid index" << endl;
            return;
        }
        int i = 0;
        Node *temp;
        temp = head;
        while (i < index - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        Node *deleteNode=temp->next;
        if (index !=i+1||deleteNode->next == NULL)
        {
            cout << "Index is out of bound " << endl;
            cout << "deleting at the end" << endl;
            deltail();
        }
        
        Node *temp1 = deleteNode->next;
        
        
        cout <<deleteNode->item<<" is deleted at the index " <<i+1<< endl;
        temp->next=temp1;
        temp1->prev=temp;
        delete deleteNode;

    }
    void forwardtraverse(){
        if(head==NULL){
            cout<<"Underflow exit"<<endl;
            return;
        }
        Node *temp;
        temp=head;
        cout<<"The value are : "<<endl;
        do{
            cout<<temp->item<<"\t";
            temp=temp->next;
            
        }while(temp!=NULL);
        cout<<endl;

    
    }
    void backwardtraverse(){
        if(tail==NULL){
            cout<<"Underflow exit"<<endl;
            return;
        }
        Node *temp;
        temp=tail;
        cout<<"The value are : "<<endl;
        do{
            cout<<temp->item<<"\t";\
            temp=temp->prev;
            
        }while(temp!=NULL);
        cout<<endl;

    
    }
};
int main()
{

    Linkedlist l1;
    int i=1,n;
    while(i==1){
        cout<<"enter 1 for insert and 2 for delete, 3 for traverse and 4 for end"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int p;
            int m;
            cout<<"Enter the value ypou want to add"<<endl;
            cin>>p;
            cout<<"Enter 1 for inserhead, 2 for end add and 3 for index add"<<endl;
            cin>>m;
            switch(m){
                case 1:
                l1.inserthead(p);
                break;
                case 2:
                l1.inserttail(p);
                break;
                case 3:
                int i;
                cout<<"Enter the index"<<endl;
                cin>>i;
                l1.insertindex(p,i);
                break;
            }
            break;
            case 2:
            int o;
            cout<<"Enter 1 for del at head ,2 for del at tail and 3 for del at index"<<endl;
            cin>>o;
            switch(o){
                case 1:
                l1.delhead();
                break;
                case 2:
                l1.deltail();
                break;
                case 3:
                int j;
                cout<<"Enter the index"<<endl;
                cin>>j;
                l1.delindex(j);
                break;

            }
            break;
            case 3:
            int t;
            cout<<"Enter 1 for forward and 2 for backward"<<endl;
            cin>>t;
            switch(t){
                case 1:
                l1.forwardtraverse();
                break;
                case 2:
                l1.backwardtraverse();
                break;

            }
            break;
            case 4:
            exit(0);
            break;

        }


    }
}