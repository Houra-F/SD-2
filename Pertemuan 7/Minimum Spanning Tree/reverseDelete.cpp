#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> iPair; //untuk menyimpan sepasang angka (angka vertex yg saing terhubung)

class Graph{
    int V;   // nyimpen total jmlh vertex
    list<int> *adj; //adjacency
    vector< pair<int, iPair> > edges; //adjacency
    void DFS(int v, bool visited[]); //menelusuri graf 

public: //bs digunakan global
    Graph(int V);   // Constructor // fungsi pertma utk membuat graf pertama x

    void addEdge(int u, int v, int w); // u dan v untuk vertex, w untuk bobot

    bool isConnected(); //mastikan terhubung atau tidk

    void reverseDeleteMST();
};

Graph::Graph(int V){ //membentuk sebaanyak apa vertex
    this->V = V;
    adj = new list<int>[V]; //untuk masing" titik
}

void Graph::addEdge(int u, int v, int w){ 
    //u terhubung dgn v, maka u sama v akan punnya hubungan timbal balik dgn bobot(w)
    adj[u].push_back(v); 
    adj[v].push_back(u); 
    edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, bool visited[]){
    visited[v] = true; //tandai sebagai true jika sdh di kunjungi agar tdk bolak balik
    
    //menandai yg mau di kunjungi(false) menjadi true stlh di kunjungi
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}


bool Graph::isConnected(){
    bool visited[V];
    memset(visited, false, sizeof(visited)); //memberi tau jika blm dikunjungi (msh false)

    DFS(0, visited);

    for (int i=1; i<V; i++)
        if (visited[i] == false)
            return false; //masih ada yg blm dikunjjungi

    return true; //dfs berhasil mengunjungi smua vertex yg ada di graf
}

// ------ Main Part of Reverse Delete -----
void Graph::reverseDeleteMST(){
    sort(edges.begin(), edges.end()); //mengurutkan dri cost yg paling kecil

    //msh kosong krn blm dikunjungi
    int mst_wt = 0;  // Initialize weight of MST

    cout << "Edges in MST\n";

    for (int i=edges.size()-1; i>=0; i--){
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        //remove edge mana yg paling besar
        adj[u].remove(v); 
        adj[v].remove(u);

        //memastikan kalau edge yg di pilih itu di delete ttp terhubung gak/ada atau tdk yg terpotong
        if (isConnected() == false){
            adj[u].push_back(v);
            adj[v].push_back(u);

            cout << "(" << u << ", " << v << ") \n";
            mst_wt += edges[i].first;
        }
    }

    cout << "Total weight of MST is " << mst_wt;
}

int main(){
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.reverseDeleteMST();
    return 0;
}