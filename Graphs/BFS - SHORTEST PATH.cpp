#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
class Graph{
    map <T, list<T> > adjList;

public:
    Graph(){

    }

    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }

    void print(){
        for(auto i : adjList){
            cout << i.first <<"->";  // change if printing an object or node

            for(auto entry : i.second){
                cout << entry << ",";  // change if printing an object or node
            }

            cout << endl ;
        }
    }

    void bfs(T src){
        queue<T> q;
        map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            cout << node <<" " ;
            q.pop();

            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true ;
                }
            }

        }
    }

    void sssp(T src, int n){
        queue<T> q;
        map<T, int> dist;
        map<T,T> parent;

        for(int i = 1; i<=n; i++){
            dist[i] = -1;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour : adjList[node]){
                if(dist[neighbour] == -1){
                    q.push(neighbour);
                    dist[neighbour] = dist[node]+1 ;
                    dist[neighbour] *= 6 ;
                    parent[neighbour] = node;
                }
            }

        }

        for(int i = 1; i<=n; i++){
            if(i != src) {
                cout << dist[i] << " ";
            }
        }
        // for(auto i : adjList){
        //     cout << i.first << " : " <<dist[i.first] << endl;
        // }
    }


};



int main(){
    int t; cin>>t;
    for(int u=0; u<t; u++){


        int ver,edge;
        cin>>ver>>edge;

        Graph<int> g;

        for(int i=0; i<edge; i++){
            int u,v;
            cin>>u>>v;
            g.addEdge(u,v);
        }
        int src;
        cin >> src;

        g.sssp(src,ver);
        cout<<endl;














    }
}
