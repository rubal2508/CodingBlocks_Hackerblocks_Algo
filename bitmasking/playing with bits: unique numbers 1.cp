#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

int coutsetbits(int n){
    int count=0;
    while (n) {
        count++;
        n = n&(n-1);
    }
    return count;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i] ;
        
    }
    
    for (int i=1; i<n; i++) {
        arr[0] = arr[0] ^ arr[i] ;
        
    }
    cout << arr[0] <<endl;
    return 0;
}
