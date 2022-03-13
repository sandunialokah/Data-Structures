#include<iostream>
#include<list>
using namespace std;

class Graph{
    int nodes;
    int edges;
    list<int> *adj;
    public:
        Graph(int n, int e):nodes(n),edges(e){}
        void create_graph();
        void add_edge(int f, int t);
        void display();
        void BFT(int start);
};

void Graph::create_graph(){
    int f, t;
    adj = new list<int>[nodes];
    for(int i=0;i<edges;i++){
        cout << "Enter edge " << i+1 << ": ";
        cin >> f >> t;
        add_edge(f,t);
    }
}

void Graph:: add_edge(int f, int t){
    
    adj[f].push_back(t);
    adj[t].push_back(f);  // this line is used only if it is an undirected graph if direct comment this line
}

void Graph::display(){
    list<int>::iterator it;
    for(int i=0;i<nodes;i++){
        cout << i << " --> ";
        for(it=adj[i].begin();it!=adj[i].end();it++){
            cout << *it << " ";
        }
        cout << " \n";
    }
}

void Graph:: BFT(int start){
    int u;
    bool visited[nodes];
    list<int> queue;
    for(int i=0;i<nodes;i++){
        visited[i]=0;
    }
    visited[start]=1;
    queue.push_back(start);

    while(!queue.empty()){
        u=queue.front();
        cout << u << " ";
        queue.pop_front();
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                visited[*it]=1;
                queue.push_back(*it);
            } 
        }
    }
}

int main(){
    int n, e;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    Graph g(n,e);
    g.create_graph();
    g.display();
    g.BFT(0);
}