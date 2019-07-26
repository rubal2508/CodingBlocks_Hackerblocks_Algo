#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;


int maxmindistance(int position[], int stalls, int cows){
    
    int s=position[0],
        e = position[stalls-1],
        final_ans= -1;
    
    
    while(s <= e) {
        
        int mid = (s + e )/2;
        int count=1;
        int curr_distance = 0;
        int pre_cow=0;

        
        for (int i=1; i<stalls; i++) {
            curr_distance = position[i]-position[pre_cow];
            if (curr_distance >= mid ) {
                pre_cow = i ;
                count++;
            }
        }
        
        if (count < cows) {
            e = mid -1 ;
        } else {
            s = mid +1 ;
            final_ans = mid ;
        }
    }
    
    return final_ans;
}


int main(){
    
    
    
        int stalls,cows;
        cin >> stalls >> cows;
        int position[stalls];
        for (int i=0; i<stalls; i++) {
            cin >> position[i];
            
        }
    
        sort(position, position+stalls);
        
        cout << maxmindistance(position, stalls, cows) << endl;
        
        
    
    
    
    
    
    return 0;
}

