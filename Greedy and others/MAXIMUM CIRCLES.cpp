#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int n; cin>>n;

    vector<pair<int,int>> v;

    while(n--){
        int a, b;
        cin>>a>>b;
        v.push_back(make_pair(a-b,a+b));
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" "<< v[i].second <<endl;
    }

    int count = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].first < v[i-1].second) {
            count++;
            i++;
        }
    }

    cout << count++;
}
