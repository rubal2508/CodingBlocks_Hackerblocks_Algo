#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;


int str_int(string s, int i)
{
    int num=0;
    //base case, i.e. string of length 1
    if(s.length()==1)
        return s[0]-'0';    ///change--
    //terminating condition, i.e. end of length of string has been reached, we have the final number
    if(i==s.length())
        return num;
    //recursive case, i.e., conversion from str to int, traversing by i and summing upto the number present in the string
    else
    {
        num=num+(s[i]-'0')*pow(10,s.length()-i-1);  ///change--
        num+=str_int(s,i+1);    ///change--
        return num;     ///change-- returning num
    }
    
}

int main()
{
    string s;
    cin>>s;
    cout<<str_int(s,0);
    return 0;
}
