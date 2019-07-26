#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>


using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    cout << s[0];
    for (int i=1; i<s.length(); i++) {
        cout  << (char)(s[i]-s[i-1]) << s[i] ;
    }
    
    
    return 0;
    
}
