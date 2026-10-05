//This code is the implementation of the B tree and its operation is applied here 

#include<iostream>
using namespace std;
const int T=2;
struct Node
{
    int value[2*T-1];
    Node* pointer[2*T];
    int count;
    bool leaf;

    Node(bool isLeaf=true){
        count =0;
        leaf=isLeaf;
 
        for(int i=0;i<2*T;i++){
            pointer[i]=nullptr;
        }

    }
};
class B_tree{
    private:
    Node *root;

    //This is the helper function for the seaching value in the tree
    void search_help(Node* current,int value){
       
            int i=0;
            //this loop helps to find the index of the root in which value can exist
            while(i<current->count&&current->value[i]<value){
                i++;

            }
            //value is found
            if(i<current->count&&current->value[i]==value){
                cout<<"Your value "<<value<<" is found"<<endl;
                return;
            }

            if(current->leaf){
                cout<<"sorry your entered value is not exist"<<endl;
                return;

            }
            search_help(current->pointer[i],value);
    }

    void display_help(Node* temp){
    int i;
    for(i=0;i<temp->count;i++){
        if(!temp->leaf){
            display_help(temp->pointer[i]);
        }
        cout<<temp->value[i]<<"\t";

    }
    if(!temp->leaf){
            display_help(temp->pointer[i]);
        }

}


    public:
    B_tree(){
        root=nullptr;
    }
    void splitChild(Node* parent,int index){
        Node* fullchild=parent->pointer[index];
        int median=fullchild->value[T-1];
        Node* newchild=new Node(fullchild->leaf);
        //Lets copy half of data into the new child
        for(int j=0;j<T-1;j++){
            newchild->value[j]=fullchild->value[j+T];

        }
        newchild->count=T-1;

        //we need to copy the pointer also if the full child is not leaf

        if(!fullchild->leaf){
            for(int j=0;j<T;j++){
                newchild->pointer[j]=fullchild->pointer[j+T];
            }
        }
        fullchild->count=T-1;
        //making space for the value median which we need to insert at the parent
        for(int j=parent->count;j>=index+1;j++){
            parent->pointer[j+1]=parent->pointer[j];
        }
       parent->pointer[index+1]=newchild;
       for(int j=parent->count-1;j>=index;j--){
        parent->value[j+1]=parent->value[j];
       }
       parent->value[index]=median;
       parent->count++;

        
        
    }

    void insert_NonFull(Node* Node,int value){
        int i=Node->count-1;

        //If leaf then directly added not splitted
        if(Node->leaf){
            while(i>=0&&Node->value[i]>value){
                Node->value[i+1]=Node->value[i];
                i--;
            }
            Node->value[i+1]=value;
            cout<<"The value "<<value<<" is added into the tree"<<endl;
            Node->count++;
            return;
        }

        //If its the interanl node then we have to split it first
        while(i>=0&&Node->value[i]>value){
            i--;
        }
        int childIndex=i+1;
        if(Node->pointer[childIndex]->count==2*T-1){
            splitChild(Node,childIndex);

            if(value>Node->value[childIndex]){
                childIndex++;
            }
        }
        insert_NonFull(Node->pointer[childIndex],value);
    }

    void insert(int value){
        if(root==NULL){
           root=new Node(true);
           root->value[0]=value;
           root->count=1;
           cout<<"The value is "<<value<<" is added at the root"<<endl;
           return;
        }
        if(root->count==2*T-1){
            Node* newroot=new Node(false);
            newroot->pointer[0]=root;
            splitChild(newroot,0);
            root=newroot;
            int i=0;
            if(root->value[0]<value){
                i=1;

            }
            insert_NonFull(root->pointer[i],value);
            
        }
        else{
            insert_NonFull(root,value);
        }

    }

    //this is the main function for seaching the value in the tree
    void search(int value){
        Node* temp;
        temp=root;
        search_help(temp,value);
    }

void display(){
    if(root==nullptr){
        cout<<"Your tree is empty"<<endl;

    }
    else{
    display_help(root);
    }
    cout<<endl;
}
};
int main(){
    B_tree b1;
    b1.insert(14);
    b1.insert(12);
    b1.insert(33);
    b1.insert(14);
    b1.insert(56);
    b1.insert(96);
    b1.insert(07);
    b1.insert(28);
    b1.insert(49);
    b1.insert(110);
    b1.display();
    b1.search(49);
    b1.search(10);
    b1.search(15);
    
  

}

