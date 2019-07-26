#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

bool isvalid(ll ans,ll n, ll k, ll len[]) {
    ll curr_sum =0, painter = 1 ;
    for (ll i = 0; i< n; i++) {
        curr_sum += len[i] ;
        if (curr_sum > ans) {
            curr_sum = len [i] ;
            painter++;
        }
    }
    if (painter > k) return false ;
    return true ;
}


ll bs (ll n, ll k, ll len[], ll ttl_len){

    ll s = len[n-1] ;
    ll e = ttl_len ;
    ll finalans = s ;
    
    while (s<=e) {
        ll mid = (s+e)/2;
        if (isvalid(mid, n, k, len)) {
            e = mid - 1 ;
            finalans = mid ;
        } else s = mid + 1 ;
    }
    
    return finalans;

}

int main(){
    ll n=0,k=0,t=0,len[n],ttl_len=0;
    cin >>n>>k>>t;
    for (ll i =0; i< n; i++) {
        cin >> len[i];
        ttl_len += len[i];
    }
    cout << (bs(n,k,len,ttl_len)*t)%10000003 <<endl;

     return 0;
}
