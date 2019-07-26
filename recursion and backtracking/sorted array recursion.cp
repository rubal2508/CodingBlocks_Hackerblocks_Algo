#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

bool issorted(int arr[], int n){
    
    if (n==1) return true;
    else  return (arr[0]<=arr[1] && issorted(arr+1, n-1));
    
    
    return false;
}

int main(){
    
    int n; cin>>n;
    int arr[n];
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    if (issorted(arr,n)) {
        cout << "true" <<endl;
    } else cout << "false" <<endl;
    
    
    return 0;
}
