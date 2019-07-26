#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(ll x=0; x<n; ++x)
#define ll long long


int main(){
    int n; int k;
    cin>>n>>k;
    int arr[n];
    unordered_map<int,int> m;
    loop(i,n){
        cin>>arr[i];
        m[arr[i]] = i ;
    }
    int max;

    loop(i,n){
        cin>>arr[i];
        m[arr[i]] = i ;
    }

    for(int i=0; i<n && k>0 ; i++){
        if(arr[i] != n-i){
            int pos = m[n-i];
            m[arr[i]] =  pos;
            swap(arr[i], arr[pos] );
            k--;
        }
    }

    loop(i,n){
        cout << arr[i]<<" ";
    }

}
