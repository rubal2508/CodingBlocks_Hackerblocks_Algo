#include <bits/stdc++.h>
using namespace std;
#define ll long long

int no_substrings(string s){
    unordered_map <string,int> hashmap;
    int n = s.length();
    int ans = 0;

    for(int i=1; i<(1<<n); i++){        //not counting empty string
            int temp = i;
            string s1 = "";
            int j = 0;


            while(temp>0 && j<n){
                if(temp&1) {
                    s1 += s1[j];
                }
                temp = temp>>1;
                j++;
            }
            cout << s1 <<endl;
            if(hashmap.count(s1) == 0) {
                hashmap[s1] = 1 ;
                ans++;
            }


    }

    return ans+1;
}





int main(){
    int t; cin>>t;
    while(t--){
        string s;
        getline(cin,s);
        cout << no_substrings(s) <<endl;
    }
}
