#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t; cin>>t;

    for(int i=0; i<t; i++){
        string str;
        cin>>str;
        int flag2 = 1;
        stack <int> s;
        for(int j=0; j<str.length(); j++){
            if(str[j] == '(') s.push(1);
            if(str[j] != ')' && str[j] != '(') s.push(2);
            if(str[j] == ')') {
                bool flag = false;
                while(s.top() != 1){
                    if(s.top()==2) flag = true;
                    s.pop();
                } s.pop();

                if(flag == false) { flag2 = 0; cout <<"Duplicate\n";  break; }
            }
        }

        if(flag2) cout<< "Not Duplicates\n";

    }


    return 0;
}
