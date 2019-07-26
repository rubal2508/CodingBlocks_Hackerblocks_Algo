#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    stack <int> s1;
    stack <int> s2;
    stack <int> s3;

    char s[10000]; cin >> s;

    for(int i=0; i<strlen(s); i++){
        if(s[i] == '(') s1.push(1);
        if(s[i] == '{') s2.push(1);
        if(s[i] == '[') s3.push(1);

        if(s[i] == ')') {
            if (s1.empty()) {cout << "No"; return 0;}
            s1.pop();
        }
        if(s[i] == '}') {
            if (s2.empty()) {cout << "No"; return 0;}
            s2.pop();
        }
        if(s[i] == ']') {
            if (s2.empty()) {cout << "No"; return 0;}
            s2.pop();
        }
    }

    if (!s1.empty() || !s2.empty()  || !s3.empty()) cout << "No";
    else cout << "Yes";
}
