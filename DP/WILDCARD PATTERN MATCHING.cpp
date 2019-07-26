#include <bits/stdc++.h>
using namespace std;
#define ll long long

int patternMatch(string str, string pat){
    int n = str.length()+1;
    int m = pat.length()+1;

    int dp[n][m];
    memset(dp, 0, sizeof(dp[0][0]) * m * n);

    dp[0][0] = 1;
    for(int i=1; i<n; i++) dp[i][0] = 0;

    for(int i=1; i<m; i++) {
        if(pat[i-1]=='*') dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){

            if(pat[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else if (pat[j-1]=='?' || pat[j-1]==str[i-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 0;
        }
    }

    return dp[n-1][m-1];
}

int main(){
    string str;
    string pat;
    getline(cin, str);
    getline(cin, pat);
    //memset(array, 0, sizeof(array[0][0]) * m * n);

    cout <<  patternMatch(str,pat);

}
