#include <bits/stdc++.h>
using namespace std;


int knapsackDP(vector<int> size, vector<int> value,  int s){
    int n = value.size();
    int dp[1050][1050];

    for(int i=0; i<1050; i++){
        for(int j=0; j<1050; j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int i=0; i<n; i++) dp[0][i] = 0;
    for(int i=0; i<=s; i++) if(i==size[0]) dp[i][0] = value[0];


    for(int i=1; i<=s; i++){
        for(int j=1; j<n; j++){
            if (i>=size[j])
            //    dp[i][j] = max (dp[i][j-1], value[j] + dp[i-size[j]][j-1]);
                dp[i][j] = min (dp[i][j-1], value[j] + dp[i-size[j]][j]);

            else
                dp[i][j] = dp[i][j-1];
        }
    }

    // for(int i=0; i<s; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << "\t";
    //     } cout << endl;
    // }

    return dp[s-1][n-1];
}


int main(){
    int n,s;
    cin>>n>>s;
    int arr[s];
    for(int i=0; i<s; i++) cin>>arr[i];

    vector<int> size;
    vector<int> value;

    for(int i=0; i<s; i++){
        if(arr[i] != -1) {
            value.push_back(arr[i]);
            size.push_back(i+1);
        }
    }





//    cout << knapsackRec(size,value,n,s) <<endl;
    cout << knapsackDP(size,value,s) <<endl;


    // for(int i=0; i<s; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << "\t";
    //     } cout << endl;
    // }



}
