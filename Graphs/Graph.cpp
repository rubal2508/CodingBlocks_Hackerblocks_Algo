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

    void sssp(T src){
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
        //    cout << node <<" " ;
            q.pop();

            for(auto neighbour : adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node]+1 ;
                    parent[neighbour] = node;
                }
            }

        }

        for(auto i : adjList){
            cout << i.first << " : " <<dist[i.first] << endl;
        }

    }

    void dfsHelper(T node, map <T, bool> &visited){
        visited[node] = true;
        cout << node <<" ";

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]) {
                dfsHelper(neighbour,visited);
            }
        }

    }
    void dfs(T src){
        map <T, bool> visited;
        dfsHelper(src,visited);
    }

    void connectedComponents(){
        map <T, bool> visited;
        int components = 0;

        for(auto i :  adjList){
            if(!visited[i.first]){
                dfsHelper(i.first,visited);
                cout << endl;
                components++;
            }
        }

        cout << "total components : "<<components<<endl;
    }

    void topoHelper(T node, map <T, bool> &visited, list <T> &ordering){
        visited[node] = true;
        //cout << node <<" ";

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]) {
                topoHelper(neighbour,visited,ordering);
            }
        }

        ordering.push_front(node);

    }
    void topoSort(){
        map <T, bool> visited;
        list <T> ordering;
        for(auto i :  adjList){
            if(!visited[i.first]) {
                topoHelper(i.first, visited, ordering);
            }
        }

        for(auto i : ordering){
            cout << i << " " <<endl;
        }
    }

    void topoSortBFS(){
        map<T, bool> visited;
        map<T, int> indegree;
        queue<T> que;

        for(auto i : adjList){
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        for(auto i : adjList){
            T node = i.first;

            for(auto neighbour : adjList[node]){
                indegree[neighbour]++;
            }
        }

        for(auto i : adjList){
            T node = i.first;
            if(indegree[node]==0) que.push(node);
        }

        while(!que.empty()){
            T node = que.front();
            que.pop();
            cout << node << "-->";

            for(auto neighbour : adjList[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) que.push(neighbour);
            }

        }

    }

    bool isCyclicBFS(T src){
        queue<T> q;
        map<T, bool> visited;
        map<T,T> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour : adjList[node]){
                if(visited[neighbour]  &&  parent[node] != neighbour)    return true;
                else if (!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true ;
                    parent[neighbour] = node;
                }
            }

        }
        return false;
    }

    bool isCyclicHelper(T node, map <T, bool> &visited, map <T, bool> &inStack){
        visited[node] = true;
        inStack[node] = true;

        bool result = false;

        for(auto neighbour : adjList[node]){
            else if((!visited[neighbour] && isCyclicHelper(neighbour,visited, inStack)) || inStack[neighbour]) {
                return true;
            }
        }

        inStack[node] = false;
        return false;
    }

    bool isCyclicDFS(){
        map <T, bool> visited;
        map <T, bool> inStack;


        for(auto i :  adjList){
            if(!visited[i.first]) {
                bool result = isCyclicHelper(i.first, visited, inStack);
                if(result) return true;
            }
        }

        return false;
    }





};

int main(){
    Graph <int> g;
     g.addEdge(1,2);
     g.addEdge(1,3);
     g.addEdge(2,4);
     g.addEdge(3,4);

    // g.connectedComponents();





}
