#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int nodes;
    int edges;
    list<int> *adj;
    public:
        Graph(int n, int e):nodes(n),edges(e){}
        void create_graph();
        void add_edge(int f, int t);
        int BFS(int src, int dest, int parent[], int dist[]);
        void shortestpath(int src, int dest);
};

void Graph::create_graph(){
    int f,t;
    adj = new list<int>[nodes];
    for(int i=0;i<edges;i++){
        cout << "Enter edge " << i+1 << ": ";
        cin >> f >> t;
        add_edge(f,t);
    }
}

void Graph:: add_edge(int f, int t){
    adj[f].push_back(t);
    //adj[t].push_back(f);  // this line is used only if it is an undirected graph if direct comment this line
}

int Graph::BFS(int src, int dest, int parent[], int dist[]){
    
    int u;
    bool visited[nodes];
    list<int> queue;
    for(int i=0;i<nodes;i++){
        visited[i]=0;
        parent[i]=-1;
        dist[i]=INT_MAX;
    }
    visited[src]=1;
    dist[src]=0;
    queue.push_back(src);
    while(!queue.empty()){
        u=queue.front();
        queue.pop_front();
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                
                visited[*it]=1;
                dist[*it]=dist[u]+1;
                parent[*it]=u;
                queue.push_back(*it);
                if(*it==dest){    
                    return true;
                }
            }
        }
        
    }
    return false;
}

void Graph::shortestpath(int src, int dest){
    int parent[nodes];
    int dist[nodes];
    if(!BFS(src,dest,parent,dist)){
        cout << "The two nodes are node connected" << endl;
        return;
    }

    vector<int> path;
    int v=dest;
    path.push_back(v);
    while(parent[v]!=-1){
        v=parent[v];
        path.push_back(v);
    }

    cout << "Shortest path length is: " << dist[dest] << endl;
    cout << "Shortest path: ";
    for(int i=path.size()-1;i>=0;i--){
        cout << path[i] << " ";
    }
}

int main(){
    int n, e, src, dest;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    Graph g(n,e);
    g.create_graph();
    cout << "Enter the start node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    g.shortestpath(src,dest);
}