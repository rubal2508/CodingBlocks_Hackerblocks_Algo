#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

int partition(int arr[],int s, int e){
    int i = s;
    for (int j=s; j<=e-1; j++) {
        if (arr[j]<=arr[e]) {
            swap(arr[i], arr[j]);
            i++;
        }
    } swap(arr[e], arr[i]);
    
    return i;
}

void quicksort(int arr[], int s, int e){
    if (s>=e) {
        return;
    }
    
    int piv = partition(arr, s, e);
    quicksort(arr, s, piv-1);
    quicksort(arr, piv+1, e);
}

void shuffle(int arr[], int s, int e){
    srand(time(NULL));
    for (int i=e; i>0; i--) {
        int j = rand()%i;
        swap(arr[i], arr[j]);
    }
}

int main() {
    
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    //sort(arr,arr+n);
    shuffle(arr,0,n-1);
    quicksort(arr,0,n-1);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] <<" ";
    } cout << endl;
    
}
