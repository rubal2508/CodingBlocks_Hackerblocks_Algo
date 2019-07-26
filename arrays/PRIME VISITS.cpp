#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SieveOfEratosthenes(int a, int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    prime[0] = false;
  
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    int count = 0;
    for (int p=a; p<=n; p++)
       if (prime[p])
          count++;

    cout << count <<endl;
}
int main(){


    int n; cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        SieveOfEratosthenes(a,b);
    }
}
