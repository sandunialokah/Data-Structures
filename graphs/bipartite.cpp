#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Graph{
    int nodes;
    int edges;
    list<int>*adj;
    public:
        Graph(int n, int e):nodes(n),edges(e){}
        void create_graph();
        void add_edge(int f, int t);
        int bipartite(int start);
};

void Graph::create_graph(){
    int f, t;
    adj = new list<int>[nodes];
    for(int i=0;i<edges;i++){
        cout << "Enter edge" << i+1 << ": ";
        cin >> f >>t;
        add_edge(f,t);
    }
}

void Graph::add_edge(int f, int t){
    adj[f].push_back(t);
    adj[t].push_back(f);
}

int Graph::bipartite(int start){
    int u;
    bool visited[nodes];
    int part[nodes];
    list<int> queue;
    for(int i=0;i<nodes;i++){
        visited[i]=0;
        part[i]=0;
    }
    visited[start]=1;
    part[start]=1;
    queue.push_back(start);
    while(!queue.empty()){
        u=queue.front();
        queue.pop_front();
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(part[u]==part[*it]){
                return false;
            }
            else{
                if(!visited[*it]){
                    visited[*it]=1;
                    part[*it]=3-part[u];
                    queue.push_back(*it);
                 }
            }
        } 
    }
    return true;
}

int main(){
    int n, e;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    Graph g(n,e);
    g.create_graph();
    if(g.bipartite(0)){
        cout << "This is a bipartite graph" << endl;
    }
    else if(!g.bipartite(0)){
         cout << "This is not a bipartite graph" << endl;
    }
}