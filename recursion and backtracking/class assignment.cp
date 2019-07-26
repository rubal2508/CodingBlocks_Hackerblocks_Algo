#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

int fibo(int n) {
    if (n==1) return 2;
    if (n==2) return 3;
    
    return fibo(n-1) + fibo(n-2) ;
    
    
}

int main() {
    int t; cin >>t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        cout <<"#"<<(i+1)<<" : "<< fibo(n) << endl ;
    }
    
}
