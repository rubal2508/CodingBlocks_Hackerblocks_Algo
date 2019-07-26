#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x)
#define ll long long


int sumofdistanctArray(int *arr,int n){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	map<int,int> m;
	int j=0,ans=0;
	for(int i=0;i<n;i++){
    	while( j<n && m.find(arr[j]) == m.end() ){
    		m.insert(make_pair(arr[j],arr[j]));     //
    		j++;
    	}
    	ans+=((j-i)*(j-i+1))/2;
    	m.erase(arr[i]);
	}
	return ans;
}





int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> map;

    loop(i,n){
        cin>>arr[i];
        if(map.count(arr[i])==0) map[arr[i]] = 1;
        else map[arr[i]]++;
    }
    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            unordered_map<int,int> map;
            bool flag = true;
            for(int k=i; k<=j; k++){
                if(map.count(arr[k])==0) map[arr[k]] = 1;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                sum += j-i+1;
            }
        }
    }

    cout<<sum;



}
