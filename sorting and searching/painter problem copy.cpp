#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll min_painter_required(ll arr[], ll n, ll time){
    ll painter=1;
    ll sum=0;

    for(ll i=0; i<n; i++){
     //   cout <<sum<<endl;
        sum += arr[i];
        if(sum>time) {
            painter++;
            sum = arr[i];
        }
    }
    return painter;
}


ll painter_problem(ll arr[], ll n, ll k){
    ll sum=0;
    ll max = arr[0];

    for(ll i=0; i<n; i++){
        sum += arr[i];
        if(arr[i]>max) max = arr[i];
    }

    ll s = max;
    ll e = sum;

    ll ans = INT_MAX;

    while(s<=e){
        ll mid = (s+e)/2;
        ll temp = min_painter_required(arr,n,mid);
        if(temp<=k) {
            e=mid-1;
            if(mid < ans) ans = mid;

        } else {
            s = mid+1;
        }

    }

    return ans;

}

int main(){
    ll n,k,t;
    cin>>n>>k>>t;
    ll arr[n];



    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<(painter_problem(arr,n,k)*t)%10000003;

    // multiply ans by t and take modulo 10000003

}
