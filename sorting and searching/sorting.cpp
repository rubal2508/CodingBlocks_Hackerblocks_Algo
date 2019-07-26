#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;


void bubblesort(int arr[], int n){
    for (int i=n-1; i>=0  ; i--) {
        for (int j=0; j<i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}



void selectionsort(int arr[], int n){
    int mini = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (arr[j]<arr[mini]) {
                mini = j;
            }
        }
        
        swap(arr[i],arr[mini]);
    }
}


void insertionsort(int arr[], int n){
    int no;
    for (int i=1; i<n; i++) {
        no=arr[i];
        int j =i-1;
        while (arr[j]>no && j>=0) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] =no;
        
    }
    
}


void linearsort(int arr[], int n){
    int freq[3]={0};
    for (int i=0; i<n;i++) {
        freq[arr[i]]++;
    }
    
//    for (int i=0; i<3;i++) {
//        cout << freq[i] << " ";
//    }
//
        for (int i =0; i<3; i++) {
            if (freq[i]==0) {
                continue;
            } else {
                for (int j=0; j<freq[i]; j++) {
                    cout << i << endl;
                }
            }
        }
}


int main(){
    
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    linearsort(arr,n);
    
    
    
    
    return 0;
}
