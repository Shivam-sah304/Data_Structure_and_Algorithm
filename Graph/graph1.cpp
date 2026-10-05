//linked list representation of the graph 
//In this program we are going to use the concept of the linked list for the representation of the graph 
//for that we are going to make two list one is the node graph and another is the adjacent list 
//in the node graph we are storing the data of our node and in the adjacent node we are storing the vertices or neighbour 
//connected to that vertex
//lets do that 

#include<iostream>
using namespace std;

struct adjacent;

struct Node{
    int data;
    Node* next;
    adjacent* adj;

};
struct adjacent{
    Node* vertex;
    adjacent *nextadj;
};

class Graph{
    private:
    Node* head;
    Node* tail;

    public:
    Graph(){
        head=nullptr;
        tail=nullptr;
    }
    void insert(int data){
        //adding data in the empty graph
        if(head==nullptr){
            Node* newnode=new Node();
            newnode->data=data;
            cout<<data<<" is added in your graph successfully!!!"<<endl;
            newnode->next=nullptr;
            newnode->adj=nullptr;
            head=newnode;
            tail=head;
            return;

        }
        //adding data to the existing graph
        Node* newnode=new Node();
        newnode->data=data;
        cout<<data<<" is added to the graph"<<endl;
        newnode->next=nullptr;
        newnode->adj=nullptr;
        tail->next=newnode;
        tail=newnode;

    }

    void join(int node1 ,int node2){
        //checking if the graph is exist or not
        if(head==nullptr){
            cout<<"your graph doesnot exist "<<endl;
            cout<<"Please make your graph first"<<endl;
            return;
        }
        //checking for the invalid index
        if(node1<0 || node2<0){
            cout<<"Invalid index"<<endl;
            return;
        }

    //initialize two node pointer for the two node 
        Node* node1ptr;
        Node* node2ptr;
        //initialize two counter for the finding of the node index
        int count1=1,count2=1;
        //if there is loop
        if(node1==node2){
            node1ptr=head;
            //finding out the index
            while(node1ptr!=nullptr&&count1<node1){
                node1ptr=node1ptr->next;
                count1+=1;
            }
            //if tree doesnot have the enough node
            if(node1ptr==nullptr){
                cout<<"Index is out of the bound"<<endl;
                return;
            }
 
        //adding in the adjacent node
            adjacent* newnode=new adjacent();
            newnode->vertex=node1ptr;
            //making one node in the adjacent node
            newnode->nextadj=nullptr;
                if(node1ptr->adj==nullptr){
                    //connecting the node list with adjacent list
                    node1ptr->adj=newnode;
                    cout<<"Your adjacent is added in the adjacent list of the index "<<count1<<endl;
                    
                    
                }
                else{
                   adjacent* temp=new adjacent();
                   //conncting the adjacent list with previous adjacent list
                   temp=node1ptr->adj;
                   while(temp->nextadj!=nullptr){
                    temp=temp->nextadj;
                    
                   }
                   temp->nextadj=newnode;
                   cout<<"Your adjacent is added in the adjacent list of the index "<<count1<<endl; 
                }


            


        }
        else{
            //finding the two index
            //first node index head
            node1ptr=head;
            while(node1ptr!=nullptr&&count1<node1){
                node1ptr=node1ptr->next;
                count1+=1;
            }
            //second node index head
            node2ptr=head;
            //checking if any node is out of the index or not
            while(node2ptr!=nullptr&&count2<node2){
                node2ptr=node2ptr->next;
                count2+=1;
            }
            
            if(node1ptr==nullptr||node2ptr==nullptr){
                cout<<"Index is out of the bound"<<endl;
                return;
            }


            adjacent* newnode=new adjacent();
            adjacent* newnode1=new adjacent();
            newnode1->vertex=node2ptr;
            newnode1->nextadj=nullptr;
            newnode->vertex=node1ptr;
            newnode->nextadj=nullptr;
            //connecting in first index node
                if(node1ptr->adj==nullptr){
                    node1ptr->adj=newnode;
                    cout<<count1<<" is added with "<<count2<<endl;
                    
                    
                }
                else{
                   adjacent* temp=new adjacent();
                   temp=node1ptr->adj;
                   while(temp->nextadj!=nullptr){
                    temp=temp->nextadj;
                    
                   }
                   temp->nextadj=newnode;
                   cout<<count1<<" is joined with "<<count2<<endl; 
                }
                //connecting in the second node with the adjacent list


                if(node2ptr->adj==nullptr){
                    node2ptr->adj=newnode1;
                    cout<<count2<<" is added with "<<count1<<endl;
                    
                    
                }
                else{
                   adjacent* temp=new adjacent();
                   temp=node2ptr->adj;
                   while(temp->nextadj!=nullptr){
                    temp=temp->nextadj;
                    
                   }
                   temp->nextadj=newnode1;
                    cout<<count1<<" is joined with "<<count2<<endl; 
                }


        }


        
    }

    //Displaying the data exist inside our graph
    void displaydata(){
        Node* temp=new Node();
        cout<<"Your data are: "<<"\t";
        temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }

    //Applying the BFS algorithm
    void BFS(int startnode){
        int count=1;
        if(head==nullptr){
            cout<<"Graph donot exist";
        }
        Node* temp=new Node();
        temp=head;

        while(temp!=NULL&&count<startnode){
            temp=temp->next;
            count++;
        }
    }


};
int main(){
    Graph g1;
    g1.join(3,3);
    g1.insert(45);
    g1.insert(56);
    g1.insert(78);
    g1.insert(90);
    g1.join(1,1);
    g1.join(3,3);
    g1.join(2,4); 
    g1.displaydata();
    
}