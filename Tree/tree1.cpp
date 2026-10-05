//In this program when the value are equal I am going to towards the right node
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;

};
class tree{
    private:
    Node *root;    
    public:
    tree(){
        root=NULL; //construcor define it to null for first condition
    }
    //This is the help fucntion of the insert function
    Node* append_value(int value){
        Node *newnode=new Node();
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    //This function helps to insert the value inside the tree
    void insert(int value){
        Node *newnode=append_value(value);
        if(root==NULL){
            
            cout<<"The value "<<value<<" is added at the root of the tree"<<endl;
            root=newnode;
            return;
        }
        Node *temp=root;
        Node *parent=NULL;
        while(temp!=NULL){
            parent=temp;
            if(value>=temp->data){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }

        if(value>=parent->data){
            cout<<"The value "<<value<<" is added towards the right node of tree"<<endl;
            parent->right=newnode;
        }
        else{
            cout<<"The value "<<value<<" is added towards the left node of tree"<<endl;
            parent->left=newnode;


        }
        
        
        
    }
    //This is help function of searching function
    Node* searchvalue(int value,Node* temp){
        //This function returns the value of node in which our value exist
        while(temp!=NULL && temp->data!=value){
            if(value>temp->data){
                temp=temp->right;

            }
            else if(value<temp->data){
                temp=temp->left;
            
            }
            else{
                temp=temp;
            }
            
        }
        return temp;

    }
//This function helps to find the value is inside the tree or not
   void seaching(int value){
    if(root==NULL){
        cout<<"sorry no any value exist "<<endl;
        cout<<"This is the underflow condition"<<endl;
        return;
    }
    Node *temp=searchvalue(value,root);
    if(temp!=NULL){
        cout<<"Found value: "<<temp->data<<endl;
    }
    else{
        cout<<"The value is not found please try with another value"<<endl;
    }
   }
//This is help function of the Delete function
   void searchparent(int value,Node* temp,Node* &parent,Node* &child){
        //This function return the parent and child node of our value want to delete
        parent=NULL;
        //It assigns that we want to delete the root value
        while(temp!=NULL && temp->data!=value){
            parent=temp;
            if(value>temp->data){
                temp=temp->right;

            }
            else {
                temp=temp->left;
            
            }
           
        }
        child=temp;


    }

//This function helps to delete value from the tree
void Delete(int value){
    if(root==NULL){
        cout<<"There is not any value in the tree"<<endl;
        cout<<"Underflow condition is occur"<<endl;
        return;
    }
    Node* parent;
    Node* child;
    
    searchparent(value,root,parent,child);
    //We get the address of parent and child node of value we want to find
    if(child==NULL){
        cout<<"Sorry "<<value<<" is not exit inside our tree"<<endl;
        return;
    }

    
    if(child->left==NULL&&child->right==NULL){
        
        cout<<value<<" is deleted form the tree "<<endl;

        if(parent==NULL){
            root=NULL;
        }
        else if(parent->left==child){
            parent->left=NULL;
            
        }
        else{
            parent->right=NULL;
            
        }
        delete child;
        
    }
    else if(child->left==NULL){
       cout<<value<<" is deleted form the tree"<<endl;
    if(parent==NULL){
        root=child->right;
    }
    
    else if(parent->left==child){
            parent->left=child->right;
            
        }
        else{
            parent->right=child->right;
           
        }
         delete child;

    }

 else if(child->right==NULL){
       cout<<value<<" is deleted form the tree"<<endl;

    if(parent==NULL){
        root=child->left;
       } 
    
    else if(parent->left==child){
            parent->left=child->left;
            
        }
        else{
            parent->right=child->left;
            
        }
        delete child;

    }
    else{
        Node *succ;
        Node *succparent=child;
        succ=child->right;
        while(succ->left!=NULL){
        succparent=succ;
            succ=succ->left;
        }
    cout<<child->data<<" is deleted from the tree"<<endl;
    child->data=succ->data;
    //disconnet the deleted node
    if(succparent->left==succ){
        succparent->left=succ->right;
    }
    else{
        succparent->right=succ->right;

    }
    delete succ;
    
    }   
}
//preorder display root->left->right

void preorder(Node *node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    inorder(node->left);
    
    inorder(node->right);
   
}
//Inorder display left->root->right

void inorder(Node *node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
   
}
//Postorder dispaly left->right->root
void postorder(Node *node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    inorder(node->right);
    cout<<node->data<<" ";
    
   
}

void display(){
    int d;
    cout<<"Enter 1 for preorder ,2 for inorder and 3 for postorder display"<<endl;
    cin>>d;
    switch(d){
        case 1:
        preorder(root);
        break;
        case 2:
        inorder(root);
        break;
        case 3:
        postorder(root);
        break;

    }
   
     cout<<endl;
}

};
int main(){
    tree t1;
    int i=1,n;
    while(i==1){
        cout<<"Enter 1 for insert ,2 for searching ,3 for delete and 4 for dispaly and 5 for exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int p;
            cout<<"Enter what you want to isnert"<<endl;
            cin>>p;
            t1.insert(p);
            break;
            case 2:
            int q;
            cout<<"Enter what you want to search"<<endl;
            cin>>q;
            t1.seaching(q);
            break;
            case 3:
            int r;
            cout<<"Enter the value what you want to delete"<<endl;
            cin>>r;
            t1.Delete(r);
            break;
            case 4:
            
            t1.display();
            break;

            case 5:
            exit(0);
            break;
            default:
            cout<<"Enter the valid number please "<<endl;
            break;

        }
    }
    
    
    
    
}