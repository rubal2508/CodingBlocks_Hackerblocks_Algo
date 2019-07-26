#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;
int subset[100][10];
int k=0;

void generatesubset(int arr[], int n, int i, int j) {
    
    if(i==n)return;

    subset[k][j] = arr[i];
    generatesubset(arr, n, i+1, j+1);
    k++;
    generatesubset(arr, n, i+1, j);
    k++;
    
}

int main() {
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        int arr[n];
        for (int j=0; j<n; j++) {
            cin >> arr[i];
        }
        generatesubset(arr, n, 0, 0);
        
        for (int j=0; j<k; j++) {
            for (int l=0; l<n; l++) {
                cout << subset[j][l] << " ";
            } cout << endl ;
        }
        
        
        k=0;
    }
    
    
}
