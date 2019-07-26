#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;





ll kthroot (ll n, ll k){
    ll start = 1, end = n, value=-1 ;
    
    while (start <= end) {
        ll mid = (start + end)/2;
        if (pow(mid,k)==n) {
            return mid;
        }
        if (pow(mid,k)>n) {
            end = mid-1;
        }
        if (pow(mid,k)<n){
            start = mid+1;
            value = mid;
        }
    }
    
    return value;
}


int main(){
    ll t; cin >> t;
    
    for (ll i=0; i<t; i++) {
        ll n,k;
        cin >>n >>k ;
        //cout << "loop" <<i <<endl ;
        cout << kthroot(n,k) <<endl;
    }
    
    
    
    
    
    
    return 0;
}

