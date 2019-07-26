#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;


ll maxbookallocation(ll books[], ll n, ll m, ll totalpages){
    
    ll s=books[n-1],
        e = totalpages,
        final_ans= s;
    
    
    while(s <= e) {
        
        ll mid = (s + e )/2;
        ll stu=1;
        ll current_pages = 0;
        
        for (ll i=0; i<n; i++) {
            current_pages = current_pages + books[i];
            if (current_pages > mid ) {
                current_pages = books[i];
                stu++;
            }
        }
        
        if (stu <= m) {
            e = mid -1 ;
            final_ans = mid ;
        } else s = mid +1 ;
    }
    return final_ans;
}


int main(){
    ll t; cin >> t;
    
    for (ll i=0; i<t; i++) {
        ll n,m,totalpages=0;
        cin >> n >> m;
        ll books[n];
        for (ll i=0; i<n; i++) {
            cin >> books[i];
            totalpages = totalpages + books[i];
        }
        
        cout << maxbookallocation(books,n,m,totalpages) << endl;
        
        
    }
    
    
    
    
    return 0;
}

