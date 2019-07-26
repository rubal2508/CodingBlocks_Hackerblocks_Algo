#include <bits/stdc++.h>
using namespace std;


bool canPlace(int** A, int i, int j, int n, int number){
    int rn = sqrt(n);
    for(int k=0; k<n; k++){
        if(A[i][k] == number || A[k][j] == number) return false;
    }

    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x=0; x<sx; x++){
        for(int y=0; y<sy; y++){
            if(A[x][y] == number) return false;
        }
    }

    return true;
}



bool solveSudoku1(int** A, int i, int j, int n){
    if(i==n) {
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
               cout<< A[x][y];
            }
            cout<<endl;
        }

        return true;
    }

    if(j==n) return solveSudoku1(A,i+1,0,n);

    if(A[i][j] != '.') return solveSudoku1(A,i,j+1,n);

    for(int number = 1; number<=9; number++){
        //cout<<number<<endl;
        if(canPlace(A,i,j,n,number)){
            A[i][j] = number;
            bool solvable = solveSudoku1(A,i,j+1,n);
            cout<<"check"<<endl;
            if(solvable){
              //  cout<<"check"<<endl;
                return true;
            }
        }


    }

    //cout<<"check"<<endl;

    A[i][j] = '.';
    return false;

}


int  main() {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n;
    cin>>n;

    int A[n][n];

    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
           cin>>A[x][y];
        }
    }

    bool flag = solveSudoku1(A,0,0,n);

}
