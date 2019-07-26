#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;



void primesieve(int arr[], int n){
    
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    
    for (int i=3; i<n; i += 2) {
        arr[i] = 1;
    }
    
    for (int i=3; i<n; i+=2) {
        if (arr[i]) {
            //mark all multiples as 0
            for (int j = i*i ; j<n; j += 2*i ) {
                arr[j] = 0 ;
            }
        }
    }
    
}

void printprimearray(int arr[], int n) {
    primesieve(arr, n);
    for (int i=0; i<n; i++) {
        if (arr[i]) cout << i <<" " ;
    }
    
    cout << endl ;
}

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    
    int a,b; cin >>a>>b;
    cout << lcm(a,b) <<endl ;
    
    return 0;
}
