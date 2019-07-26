#include <bits/stdc++.h>
using namespace std;
#define ll long long


int knapsackDP(int arr[], int n, int s){

    int dp[1000][50];

    for(int i=0; i<1000; i++){
        for(int j=0; j<50; j++){
            dp[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++) {
        // if(arr[i]==0 || dp[0][i-1]==1)  dp[0][i] = 1 ;
        // else dp[0][i] = 0
        dp[0][i] = 1 ;
    }
    for(int i=0; i<=s; i++){
        if(i==arr[0]) dp[i][0] = 1;
        else dp[i][0] = 0;
    }

    for(int i=1; i<=s; i++){
        for(int j=1; j<n; j++){
            if (i>=arr[j])
                  dp[i][j] =  dp[i][j-1] | dp[i-arr[j]][j-1];
            //    dp[i][j] = max (dp[i][j-1], value[j] + dp[i-size[j]][j]);

            else
                dp[i][j] = dp[i][j-1];
        }
    }


    return dp[s][n-1];
}


int main(){
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }





//    cout << knapsackRec(size,value,n,s) <<endl;
    cout << knapsackDP(arr,n,s) <<endl;


    // for(int i=0; i<s; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << "\t";
    //     } cout << endl;
    // }



}
