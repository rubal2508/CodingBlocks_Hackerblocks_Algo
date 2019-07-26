#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

void mysort(int arr[], string s[], int n){
    for (int i=n-1; i>=0  ; i--) {
        for (int j=0; j<i; j++) {
            if (arr[j]<arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swap(s[j], s[j+1]);
            }
            
            if ((arr[j]==arr[j+1]) && (s[j]>s[j+1])) {
                swap(arr[j], arr[j+1]);
                swap(s[j], s[j+1]);
            }
        }
    }
    
}

int main(){
    
    int x; cin >> x;
    int n; cin >> n;
    string s[n];
    int arr[n];
    
    for (int i =0; i<n; i++) {
        cin>> s[i];
        cin>> arr[i];
    }
    
    mysort(arr,s,n);
    
    for (int i =0; i<n; i++) {
        if(arr[i]<x){ break;}
        cout<< s[i] <<" ";
        cout<< arr[i] <<endl;
        
    }
    
    
    return 0;
}
