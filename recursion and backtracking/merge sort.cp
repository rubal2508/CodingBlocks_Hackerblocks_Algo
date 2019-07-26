#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

void merge(int arr[], int s, int e){
    int mid= (s+e)/2;
    int arr1[e+1];
    int i=s, j=mid+1, k=s;
    
    while (i<=mid || j<=e) {
        if(i==mid+1) {
            arr1[k]=arr[j];
            k++; j++;
            continue;
        }
        if(j==e+1) {
            arr1[k]=arr[i];
            k++; i++;
            continue;
        }
        
        if (arr[i]<=arr[j]) {
            arr1[k]= arr[i];
            i++; k++;
        } else {
            arr1[k]= arr[j];
            k++; j++;
        }
    }
    
    for (int i=s; i<=e; i++) {
        arr[i]= arr1[i] ;
    }

}

void mergesort(int arr[], int s, int e){
    
    
    if (s>=e) {
        return;
    }
    int mid= (s+e)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    
    merge(arr,s,e);
    
}

int main() {
    
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    mergesort(arr, 0, n-1);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] <<" ";
    } cout << endl;
    
}
