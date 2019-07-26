#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1000][1000];


ll plateDropping(ll plates, ll floors){

    if(floors==0 || floors==1) return floors;
    if(plates==1) return floors;

    if(dp[plates][floors] != -1) return dp[plates][floors];

    ll ans = INT_MAX;

    for(ll i=1; i<=floors; i++){
        ll temp = max (plateDropping(plates-1,i-1), plateDropping(plates,floors-i));
        if(temp < ans) ans = temp;
    }

    dp[plates][floors] = ans + 1;
    return ans+1;
}



int main(){
    ll t; cin>>t;


    for(ll i=0; i<1000; i++){
        for(ll j=0; j<1000; j++){
            dp[i][j] = -1;
        }
    }

    while(t--){
        ll plates,floors;
        cin>>plates>>floors;
        cout << plateDropping(plates,floors)<<endl;
    }
}
