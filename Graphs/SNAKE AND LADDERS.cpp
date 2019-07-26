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

    void sssp(T src, T dest){
        queue<T> q;
        map<T, int> dist;
        map<T,T> parent;

        for(auto i : adjList){
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour : adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node]+1 ;
                    parent[neighbour] = node;
                }
            }

        }

        cout << dist[dest]<<endl;
    }


};



int main(){
    int t; cin>>t;
    //cout <<t<<endl;

    for(int u=0; u<t; u++){
        int n,l,s;
        cin>>n>>l>>s;

        //cout <<n<<l<<s<<endl;

        int arr[100] = {0};

        for(int i=0; i<l+s; i++){
            int start,end;
            cin>>start>>end;
            arr[start] = end - start;
        }

        // for(int i=0; i<n+1; i++){
        //     cout << arr[i] << " ";
        // }

        Graph <int> g;

        for(int i=1; i<=n; i++){
            g.addEdge(i,i+1+arr[i+1],false);
            g.addEdge(i,i+2+arr[i+2],false);
            g.addEdge(i,i+3+arr[i+3],false);
            g.addEdge(i,i+4+arr[i+4],false);
            g.addEdge(i,i+5+arr[i+5],false);
            g.addEdge(i,i+6+arr[i+6],false);
        }

        //g.print();
        g.sssp(1,n);


    }
}
