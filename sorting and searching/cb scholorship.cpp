include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

bool isvalid(int ans,int n, int m, int x, int y) {
    if ((ans*x)<= m + (n - ans)*y) {
        return true;
    } else return false ;
}

int maxstudents (int n, int m, int x, int y){
    int s = 0 , e = n , max = 0;
    while (s<=e) {
        int mid = (s + e )/2;
        if (isvalid(mid,n,m,x,y)) {
            s = mid + 1;
            max = mid ;
        } else e = mid-1 ;
    }
    
    return max;
}


int main(){
    
    int t ; cin >> t;
    for (int i= 0; i<t; i++) {
        int n,m,x,y;
        cin >>n>>m>>x>>y;
        cout << maxstudents(n,m,x,y) <<endl;
    }
     return 0;
}