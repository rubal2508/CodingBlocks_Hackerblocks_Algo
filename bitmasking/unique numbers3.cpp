#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

int countsetbits(int n){
    int count=0;
    while (n) {
        count++;
        n = n&(n-1);
    }
    return count;
}

int findsetbit(int n){
    int i=0;
    while (n) {
        if (n&1) {
            break;
        }
        else {
            i++;
            n= n>>1;
        }
    }
    
    return i;
}

int findunique(int arr[], int n){
    int count[64] = {0} ;
    
    for (int i=0; i<n; i++) {
        int no = arr[i];
        int j=0;
        while (no>0) {
            count[j] = (no&1);
            j++;
            no = (no>>1);
        }
        
    }
    
    for (int i=0; i<64; i++) {
        count[i] = count[i]%3;
    }
    
    int num=0;
    
    for (int i=0; i<64; i++) {
        if(count[i]>0){
            num = num + (1<<i);
        }
    }
    
    return num;
}


int main(){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i] ;
        
        
    }
    cout << findunique(arr,n) << endl;
    

    
    return 0;
}
