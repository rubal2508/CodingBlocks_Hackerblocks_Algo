#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int>> > adjList;

public:
    Graph(){

    }

    void addEdge(T u, T v, int w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if(bidir) adjList[v].push_back(make_pair(u,w));
    }

    void print(){
        for(auto i : adjList){
            cout << i.first <<"->";  // change if printing an object or node

            for(auto entry : i.second){
                cout<<"(" << entry.first << "," << entry.second <<") " ;  // change if printing an object or node
            }

            cout << endl ;
        }
    }

    void dijkstra(T src){
        unordered_map<T,int> dis;
        set<pair<int,T> > s;

        for(auto i : adjList){
            dis[i.first] = INT_MAX;
        }

        dis[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            T node = *(s.begin()).second;
            int d =  *(s.begin()).first;
            s.erase(s.begin());

            for(auto p : adjList[node]){
                T n = p.first;
                int w = p.second;
                if(dis[n] > dis[node] + w){
                    auto i = s.find(make_pair(dis[n],n));
                    if(i != s.end()){
                        s.erase(i);
                    }
                    dis[n] = dis[node] + w;
                    s.insert(make_pair(dis[n],n));
                }
            }
        }
    }


};
