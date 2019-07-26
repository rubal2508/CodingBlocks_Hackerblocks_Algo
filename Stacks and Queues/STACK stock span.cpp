#include <bits/stdc++.h>
#define ll long long
using namespace std;

void stockspan(int arr[], int n){
    int span[n] = {0};
    stack <int> s;


    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()]<arr[i])  {s.pop();}

        if(s.empty()) span[i] = i+1;
        else span[i] = i-s.top();
        s.push(i);
    }

    for(int i=0; i<n; i++){
        cout << span[i] << " ";
    }
    cout<< "END ";
}


int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    stockspan(arr,n);

}
