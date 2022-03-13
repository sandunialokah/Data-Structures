#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Graph{
    int nodes;
    int edges;
    list<int> *adj;
    public:
        Graph(int n, int e):nodes(n),edges(e){}
        void create_graph();
        void add_edge(int f, int t);
        int iscycle(int start);
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

void Graph::add_edge(int f, int t){
    adj[f].push_back(t);
    adj[t].push_back(f);
}

int Graph::iscycle(int start){
    bool visited[nodes];
    int parent[nodes];
    list<int>queue;
    for(int i=0;i<nodes;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    visited[start]=1;
    queue.push_back(start);
    while(!queue.empty()){
        int u=queue.front();
        queue.pop_front();
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                visited[*it]=1;
                parent[*it]=u;
                 queue.push_back(*it);
            }
            else if(parent[u]!=*it){
                return true;
            }

        }
    }
    return false;
}

int main(){
    int n, e;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    Graph g(n,e);
    g.create_graph();
    if(g.iscycle(0)){
        cout << "There is a cycle" << endl;
    }
    else if(!g.iscycle(0)){
        cout << "There is no cycle" << endl;
    }
    
}