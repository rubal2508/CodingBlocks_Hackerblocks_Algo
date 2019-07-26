#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

ll partition(ll arr[],ll s, ll e){
    ll i = s;
    for (ll j=s; j<=e-1; j++) {
        if (arr[j]<=arr[e]) {
            swap(arr[i], arr[j]);
            i++;
        }
    } swap(arr[e], arr[i]);
    
    return i;
}

void quicksort(ll arr[], ll s, ll e){
    if (s>=e) {
        return;
    }
    
    ll piv = partition(arr, s, e);
    quicksort(arr, s, piv-1);
    quicksort(arr, piv+1, e);
}

int main() {
    
    ll n; cin >> n;
    ll arr[n];
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    quicksort(arr,0,n-1);
    
    for (ll i=0; i<n; i++) {
        cout << arr[i] <<" ";
    } cout << endl;
    
}
