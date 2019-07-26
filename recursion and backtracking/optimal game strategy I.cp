#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;
int value = 0;

void maxvalue(int arr[], int s, int e){
    if (s > e) {
        return ;
    }
    
    if (arr[s] >= arr[e]) {
        value += arr[s] ;
        s++;
        if (arr[s] >= arr[e]) {
            maxvalue(arr, s+1, e);
        } else {
            maxvalue(arr, s, e-1);
        }
        
    } else {
        value += arr[e] ;
        e--;
        if (arr[s] >= arr[e]) {
            maxvalue(arr, s+1, e);
        } else {
            maxvalue(arr, s, e-1);
        }
    }
    
    
    
}


int main() {
    int n; cin >> n;
    int arr[n];
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    maxvalue(arr,0,n-1);
    cout << value ;
    
    
    
}
