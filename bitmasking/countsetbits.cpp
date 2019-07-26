#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

int countsetbits(int n){
    int count=0;
    while (n) {
        count++;
        n = n&(n-1);
    }
    return count;
}

int main(){
    int n; cin >>n;
    
    for (int i=0; i<n; i++) {
        cout << countsetbits(i) <<endl;
    }
    
    return 0;
}
