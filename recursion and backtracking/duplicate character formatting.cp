#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

void printstr(char arr[], int i){
    if (arr[i]=='\0') return;
//    if (arr[i+1]=='\0') {cout<<arr[i]; return;}

    
    if (arr[i] == arr[i+1]) {
        cout << arr[i] << "*" ;
        printstr(arr, i+2);
    } else {
        cout << arr[i];
        printstr(arr, i+1);
        
    }
    
}


int main() {
//    int t; cin >> t;
//    for (int i=0; i<t; i++) {
        char arr[10000]={'\0'};
        cin >> arr;
        
        printstr(arr, 0);
        cout << endl;
 //   }
    
    
}
