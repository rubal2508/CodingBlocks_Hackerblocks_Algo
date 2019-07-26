#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_area = 0;

void histogram(ll arr[], ll n){
    stack <ll> s;
    ll i=0;
    ll area = 0;
    while(i<n){
        if(s.empty() || arr[i] >= arr[s.top()]) {
            s.push(i);
            i++;
        }
        else {
                ll top = s.top();
                s.pop();
                if(!s.empty()) {
                     area = arr[top]*(i-s.top()-1);
                } else {
                     area = arr[top]*i;
                }
                if (area>max_area) max_area = area;
        }
    }
    while(!s.empty()){
        ll top = s.top();
        s.pop();
        if(!s.empty()) {
            area = arr[top]*(i-s.top()-1);
        } else {
             area = arr[top]*i;
        }
        if (area>max_area) max_area = area;
    }
    cout << max_area;

}

int main(){
    ll n; cin>>n;
    ll arr[n];
    for(ll i = 0; i<n; i++){
        cin >> arr[i];
    }
    histogram(arr,n);
}
