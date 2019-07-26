#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    stack <int> s;


    int Q; cin>>Q;
    for(int i=0; i<Q; i++){
        int flag; int cost;
        cin >> flag;
        if (flag == 1){
            if (s.empty()){cout << "No Code"; continue;}
            cout << s.top() << endl;
            s.pop();
            continue;
        }
        if (flag==2) {
            cin << cost;
            s.push(cost);
        }
    }
}
