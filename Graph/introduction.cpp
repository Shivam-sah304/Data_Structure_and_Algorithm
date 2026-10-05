#include<iostream>
#include<cstdlib>
using namespace std;

int const maxnode=5; 
class Graph{
    private:
    int node[maxnode];
    int adj[maxnode][maxnode];
    int i=0,j;   
    public:
    Graph(){
        for(i=0;i<maxnode;i++){
            for(j=0;j<maxnode;j++){
                adj[i][j]=0;
            }
        }
    }
    void insert(int data,int Node){
        if(Node<=maxnode){
            node[Node-1]=data;
            cout<<data<<" is added at the "<<Node<<" node"<<endl;
            

        }
        else{
            cout<<"Tree is full !!!!!!!!!"<<endl;
        }
    }
    void join(int node1,int node2){
        if(node1<=maxnode && node2<=maxnode){
            adj[node1-1][node2-1]=1;
            cout<<node1<<" is connected with "<<node2<<endl;
            adj[node2-1][node1-1]=1;
            cout<<node2<<" is coneected with "<< node1<<endl;

        }
        else{
            cout<<"Your index is out of the node"<<endl;
        }
    }
    void displaydata(int data){
        for(i=0;i<maxnode;i++){
            if(node[i]==data){
                cout<<"Your data is at the node "<<i+1<<endl;
                break;
            }
        }

    }
    void adjdispaly(){
        cout<<"Your adjacent matrix is : "<<endl;
        cout<<"  ";
        for(i=0;i<maxnode;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        for(i=0;i<maxnode;i++){
            cout<<i<<" ";
            for(j=0;j<maxnode;j++){
                cout<<adj[i][j]<<" ";

            }
            cout<<endl;
        }
    }
    void BFSalgorithm(int startnode,int value){
        int queue[maxnode];
        int front=0,rear=0;
        bool visited[maxnode]={false};
        int currentnode;
        
        queue[rear]=startnode-1;
        visited[startnode-1]=true;
        rear=rear+1;
        cout<<"BFS algorithm: "<<"\t";
        while(front<rear){
            currentnode=queue[front];
            if(value==node[currentnode]){
                cout<<"Your value is found at the "<<currentnode+1<<" node"<<endl;
                break;
            }
            cout<<currentnode+1<<"\t";
           
            for(int i=0;i<maxnode;i++){
                if(adj[currentnode][i]==1&&!visited[i]){
                    visited[i]=true;
                    queue[rear]=i;
                    rear=rear+1;
                }
                
            }
             front=front+1;


        }
        cout<<endl;

    }

void search(int startnode,bool visited[maxnode],int stack[maxnode],int &top){
    visited[startnode]=true;
    stack[++top]=startnode;
    for(int i=0;i<maxnode;i++){
        if(adj[startnode][i]==1&&!visited[i]){
            search(i,visited,stack,top);
        }
    }

}

    void DFSalgorithm(int startnode,int value){
            int top=-1;
            int stack[maxnode];
            bool visited[maxnode]={false};
            search(startnode,visited,stack,top);
            cout<<"DFS traversal "<<"\t";
            for(i=0;i<=top;i++){
                if(node[i]==value){
                    cout<<"Your value is found at "<<i+1<<" node"<<endl;
                    break;
                }
                cout<<stack[i]+1<<"\t";
            }
            cout<<endl;

    }
};
int main(){
    Graph g1;
    int i=1,n;
    while(i==1){
        cout<<"Enter 1 for insert , 2 for join ,3 for searching and 4 for disaply adjacent matrix and 5 for exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
            int d,i;
            cout<<"Enter the data you want to add"<<endl;
            cin>>d;
            cout<<"Enter the index at which you want to add"<<endl;
            cin>>i;
            g1.insert(d,i);
            break;
            case 2:
            int j,k;
            cout<<"Enter the nodes you want to join"<<endl;
            cin>>j>>k;
            g1.join(j,k);
            break;
            case 3:
            int p;
            cout<<"Enter the start index"<<endl;
            cin>>p;
            int b;
            cout<<"Enter 1 for BFS search and 2 for DFS search "<<endl;
            cin>>b;
            int v;
            cout<<"Enter the value you want to search "<<endl;
            cin>>v;
            switch(b){
                case 1:
                 g1.BFSalgorithm(p,v);
                 break;
                case 2:
                g1.DFSalgorithm(p-1,v);
                break;

            }

            
           
            break;
            case 4:
            g1.adjdispaly();
            break;
            case 5:
            exit(0);
            break;

        }
    }
    
}