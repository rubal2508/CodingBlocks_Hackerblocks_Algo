#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };


string output[10000000];
int count =0;

void codes(char in[], char out[], int i){
    // base case
    if (in[i]== '\0') {
        out[i] = '\0';
        cout << out << endl ;
        return;
    }
    
    int k=0;
    while (table[in[i]-'0'][k] != '\0') {
        
        out[i] = table[in[i]-'0'][k] ;
        codes(in, out, i+1);
        k++;
    }
    
}

int main() {
    
    char in[100], out[100]; cin>> in;
    
    codes(in,out,0);
    
    
}
