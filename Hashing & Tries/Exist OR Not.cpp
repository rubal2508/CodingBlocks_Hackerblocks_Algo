#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x)




int main(){

        int n; cin>>n;
        int arr[n];
        vector<int> v1;
        unordered_map<int,vector<int>> m;

        loop(i,n){
            cin>>arr[i];
            m[arr[i]].push_back(arr[i]);
        }
        //

        loop(i,n){
            int d; cin>>d;
            if(m.count(d) && m[d].size()>0) {
                v1.push_back(d);
                m[d].pop_back();
            }

        }

        sort(v1.begin(), v1.end());
        cout<<"[";
        loop(i,v1.size()-1) {
            cout << v1[i] <<", ";
        }
        cout<<v1[v1.size()-1]<<"]";


}
