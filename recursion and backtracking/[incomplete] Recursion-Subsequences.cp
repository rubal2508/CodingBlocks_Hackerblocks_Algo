#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

string s[100000];
int k =0;

void subseq(char in[], char out[], int i, int j){
    
    if (i== '\0') {
        out[j]= '\0';
        s[k] = out ;
        k++;
        return;
    }
    
    subseq(in, out, i+1, j);
    out[j] =  in[i];
    subseq(in, out, i+1, j+1);
    
    
    
}


int main() {
    
    int n; cin >> n;
    //    int arr[n];
    //    for (int i=0; i<n; i++) {
    //        cin >> arr[i];
    //    }
    
    for (int i=0; i<n; i++) {
        char in[100]; cin>>in ;
        char out[100];
        
        subseq(in, out, 0, 0);
        sort(s,s+k);
        for (int i=0; i< k ; i++) {
            cout << s[i] <<endl;
        }
        k=0;
    }
    
    
    return 0;
    
    //    for (int i=0; i<n; i++) {
    //        cout << arr[i] <<" ";
    //    } cout << endl;
    
}
