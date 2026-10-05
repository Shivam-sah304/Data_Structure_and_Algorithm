//In this program we want to add at the middle or anywhere we want to 
//add
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int item;
    Node *next;
};
class linear_list{
    private:
    Node *next; 
    Node *head;
    Node *tail;
    
    public:
    linear_list(){
        next=NULL;
        head=NULL;
        tail=NULL;
    }
    void inserthead(int value){
        if(head==NULL){
            head=new Node();
            head->item=value;
            cout<<value<<" is added to your list"<<endl;
            head->next=next;
            tail=head;
            return;
        }
        Node *temp=new Node();
        temp->item=value;
        cout<<value<<" value is added to the linear list"<<endl;
        temp->next=head;
        head=temp;



    }
    void inserttail(int n){
        if(head==NULL){
            head=new Node();
            head->item=n;
            cout<<n<<" is added to your list"<<endl;
            head->next=next;
            tail=head;
            return;
        }
        Node *newnode=new Node();
        newnode->item=n;
        cout<<n<<" value is added to the linear list"<<endl;
        tail->next=newnode;
        
        newnode->next=next;
        tail=newnode;
    }
    void deltail(){
        if(head==NULL){
            cout<<"No more value is available"<<endl;
            return;
        }
        
        if (head == tail) { // Only one item exists
            cout << head->item << " is deleted from the list" << endl;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        
        
        Node *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        cout<<tail->item<<" is deleted from the list"<<endl;
        delete tail;
        tail=temp;
        tail->next=NULL; 
        
    

    }

    void insertindex(int value,int index){ 
        Node *temp=head;
        int i=0;
        Node *newnode=new Node();
        if(index==0 || head==NULL){
            newnode->item=value;
            cout<<value<<" is added to your list"<<endl; 
            newnode->next=head;
            head=newnode;
            if(tail==NULL){
                tail=head;

            }
            return;
        }

        while(i<index-1){
            
            if(temp->next==NULL){
                cout<<"The list is not as long as you think"<<endl;
                cout<<"So we are adding at the end"<<endl;
                inserttail(value);
                return;
                

            }
            temp=temp->next;
            i++;
        }
        if (temp == tail) {
        inserttail(value);
        return;
    }
       
        newnode->item = value;
        newnode->next = temp->next;
        temp->next = newnode;
        cout << value << " added at index " << index << endl;
    }
    
    
    void Deletehead(){ 
        if(head==NULL){
            cout<<"No more value is available "<<endl;
            return;

        }
        Node *temp=head;
        cout<<head->item<<" is deleted"<<endl;
        head=head->next;
        
        delete temp;


    }
    void delindex(int index){
        Node *temp;
        if(head==NULL){
            cout<<"No any value available "<<endl;
            return;

        }
        if(index<0){
            cout<<"Invalid index"<<endl;
            return;
        }
        if(index==0){
            Deletehead();
            return;

        }
        int i=0;
        temp=head;
        if(temp->next==NULL){
            cout<<"Only one value available"<<endl;
            cout<<temp->item<<" is deleted "<<endl;
            delete head;
            head=NULL;
            tail=NULL;
            return;
        }
        while(i<index-1&&temp->next!=NULL){
            
            i++;
            temp=temp->next;
        }
        if(temp->next==NULL){
            cout<<"Your entered index is out of bound"<<endl;
            cout<<"We are deleting the last index"<<endl;
            deltail();
            return;
        }
        Node *newnode=temp->next;
        if(newnode == tail) {
        tail = temp;
        tail->next = NULL;
    } else {
        temp->next = newnode->next;
    }

    cout << newnode->item << " is deleted from index " << index << endl;
    delete newnode;
}
    }

;
int main(){
    linear_list l1;
    
    int i=1;
    while(i==1){
        int n;
        cout<<"Enter 1 for insert and 2 for delete, 3 for exit"<<endl;
        
        cin>>n;
        switch (n)
        {
        case 1:
            int p,m;
            cout<<"Enter 1 for insert from head 2 for insert from tail and 3 for required index"<<endl;
            cin>>m;
            cout<<"Enter your value you want to add"<<endl;
            cin>>p;
            switch(m){
                case 1:
                l1.inserthead(p);
                break;
                case 2:
                l1.inserttail(p);
                break;
                case 3:
                int i;
                cout<<"Enter your index please"<<endl;
                l1.insertindex(p,i);
                break;
            }
            
            break;
        case 2:
        int o;
        cout<<"Enter 1 for delete from head , 2 for delete from tal and 3 for delete from required index"<<endl;
        cin>>o;
        switch (o)
        {
        case 1:
            l1.Deletehead();
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
        exit(0);
        break;
         
        
        default:
        cout<<"Enter the valid number "<<endl;
            break;
        }

    }

}