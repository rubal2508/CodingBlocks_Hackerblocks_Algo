#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#define ll long long
using namespace std;

int chessboard[100][100] = {0};

void printboard(int n) {
    for (int i=0; i<n; i++) {
        for (int j =0; j<n; j++) {
            cout << chessboard[i][j] <<"\t";
        } cout << endl;
    }
}

bool can_place(int n, int row, int col) {
    for (int i=0 ; i<n; i++) {
        if (chessboard[row][i]==1 || chessboard[i][col]==1) {
            return false;
        }
    }
    int i = row;
    int j = col ;
    while (i>=0 && j>=0) {
        if (chessboard[i--][j--]==1) {
            return false;
        }
    }
    
    i = row;
    j = col ;
    while (i<n && j<n) {
        if (chessboard[i++][j++]==1) {
            return false;
        }
    }
    
    i = row;
    j = col ;
    while (i>=0 && j<n) {
        if (chessboard[i--][j++]==1) {
            return false;
        }
    }
    
    i = row;
    j = col ;
    while (i<n && j>=0) {
        if (chessboard[i++][j--]==1) {
            return false;
        }
    }
    
    return true ;
}

bool queen_problem(int n, int current){
    if (current>=n) {
        return true;
    }
    
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (can_place(n, i, j)) {
                chessboard[i][j] = 1;
                if (queen_problem(n, current+1)) return true;
                chessboard[i][j] = 0;
            }
        }
    }
    
    return false;
}


int main(){
    int n=5 ;
    if (queen_problem(n, 0)) {
        printboard(n);
    } else cout << "sorry" <<endl ;
}
