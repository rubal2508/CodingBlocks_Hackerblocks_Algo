#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;


int upperbound(int arr[], int n, int key) {
    int index = -1;
    int start = 0, end = n-1;
    
    while(start <= end){
        int mid = (start + end )/2;
        if (key==arr[mid]) {
            index = mid ;
            start = mid + 1;
        }
        if (key < arr[mid]) {
            end =  mid -1;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        }
        
        
    }
    
    
    return index;
}

int main(){
    
    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int num; cin>> num;
    
    
    cout << upperbound(arr, n, num);
    
    
    return 0;
}
