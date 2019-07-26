#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;
string s[10000];
int k =0;

void permute(char arr[] , char ch[] , int i ){
    
    if (ch[i] == '\0') {
        if (strcmp(ch, arr) > 0){
            s[k] = ch ;
            k++;
        }
            
        return ;
    }
    
    for (int j=i; ch[j] != '\0' ; j++) {
        swap(ch[i], ch[j]);
        permute(arr, ch, i+1);
        swap(ch[i], ch[j]);
    }
    
    
}


int main() {
    
    char ch[1000], arr[1000];
    cin >> ch ;
    strcpy (arr,ch);
    permute(arr, ch, 0);
    
    sort(s, s+k);
    for (int i=0; i<n; i++) {
        cout << s[i] <<endl;
    }
    
    
}
