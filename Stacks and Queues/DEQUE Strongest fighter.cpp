#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(int x = 0; x < n; ++x)

void slidingwindow(int arr[], int n, int k){
    deque <int> Q(k);
    int i;
    for(i=0; i<k; i++){
        while(!Q.empty() && arr[i]>arr[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    for(; i<n; i++){
        cout << arr[Q.front()] <<" ";
        while(!Q.empty() && Q.front()<=(i-k)) Q.pop_front();
        while(!Q.empty() && arr[Q.back()]<=arr[i]) Q.pop_back();
        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<endl;
}


int main(){
    int n;  cin>>n;
    int arr[n];
    loop(i,n) cin>>arr[i];
    int k; cin>>k;

    slidingwindow(arr,n,k);
}
