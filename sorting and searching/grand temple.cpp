#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n ; cin >> n ;
    int x[n] , y[n] ;
    int max_diff_x = 0 , max_diff_y = 0;
    
    for (int i = 0; i<n;  i++) {
        cin >> x[i] >> y[i] ;
    }
    sort(x,x+n);
    sort(y,y+n);
    
    for (int i = 0; i<n;  i++) {
        if (x[i]-x[i-1]>= max_diff_x) {
            max_diff_x = x[i]-x[i-1] ;
        }
        if (y[i]-y[i-1]>= max_diff_y) {
            max_diff_y = y[i]-y[i-1] ;
        }
    }
    
    cout << (max_diff_x-1)*(max_diff_y-1) << endl ;
    
    return 0;
}
