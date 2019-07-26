#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[5000][5000];
ll arr[5000];

ll optimalGame(ll i, ll j){
    //if(i<j) return 0;
   if(j-i == 1) return max(arr[i],arr[j]);

    if(dp[i][j] != -1) return dp[i][j];

    ll ans1 = arr[i] + min(optimalGame(i+2,j) , optimalGame(i+1,j-1));
    ll ans2 = arr[j] + min(optimalGame(i,j-2) , optimalGame(i+1,j-1));

    ll ans = max(ans1,ans2);
    dp[i][j]=ans;
    return ans;
}




int main(){
    ll n; cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    for(ll i=0; i<5000; i++){
        for(ll j=0; j<5000; j++){
            dp[i][j] = -1;
        }
    }

    cout << optimalGame(0,n-1) <<endl;



}
