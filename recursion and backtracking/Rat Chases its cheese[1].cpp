#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

char maze[1000][1000];
int result[1000][1000];

void printresult(int n, int m){
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << result[i][j] <<" " ;
        } cout << endl ;
    }
    cout << endl;
}

bool ratmaze(int n, int m, int row, int col) {

    if (row>=n || col >=m || row<0 || col<0) {							// row>=n || col >=m || <0
        return false;
    }
    if (row==(n-1) && col == (m-1)) {
        //printresult(n,m);
        return true ;
    }

    if (maze[row][col+1] == 'O') {    //move right
		cout << "moving right\n" ;
		result[row][col+1] = 1 ;
        if(ratmaze(n, m, row, col+1)) return true;
        result[row][col+1] = 0;
		cout << "cancelling right\n" ;


    }
	if (maze[row+1][col] == 'O') { 		//move down
		cout << "moving down\n" ;
		result[row+1][col] = 1 ;
        if(ratmaze(n, m, row+1, col)) return true;
        result[row+1][col] = 0;
		cout << "cancelling down\n" ;

    }
	if (maze[row][col-1] == 'O'  && col>0) {    //move left
			cout << "moving left\n" ;
			result[row][col-1] = 1 ;
		    if(ratmaze(n, m, row, col-1)) return true;
		    result[row][col-1] = 0;
			cout << "cancelling left\n" ;

	}

	if (maze[row-1][col] == 'O'  && row>0) {
			cout << "moving up\n" ;									//move up
		    result[row-1][col] = 1 ;
		    if(ratmaze(n, m, row-1, col)) return true;
		    result[row-1][col] = 0;
			cout << "cancelling up\n" ;

	}

    return false ;
}

bool ratmaze2(int n, int m, int row, int col, int FLAG) {

    if (row>=n || col >=m || row<0 || col<0) {							// row>=n || col >=m || <0
        return false;
    }
    if (row==(n-1) && col == (m-1)) {
        //printresult(n,m);
        return true ;
    }

    if (maze[row][col+1] == 'O' && FLAG != 'L') {    //move right
	//	cout << "moving right\n" ;
		result[row][col+1] = 1 ;
        if(ratmaze2(n, m, row, col+1,'R')) return true;
        result[row][col+1] = 0;
	//	cout << "cancelling right\n" ;
    }

	if (maze[row+1][col] == 'O' && FLAG != 'U') { 		//move down
	//	cout << "moving down\n" ;
		result[row+1][col] = 1 ;
        if(ratmaze2(n, m, row+1, col, 'D')) return true;
        result[row+1][col] = 0;
	//	cout << "cancelling down\n" ;

    }
	if (maze[row][col-1] == 'O'  && col>0 && FLAG != 'R') {    //move left
		//	cout << "moving left\n" ;
			result[row][col-1] = 1 ;
		    if(ratmaze2(n, m, row, col-1, 'L')) return true;
		    result[row][col-1] = 0;
		//	cout << "cancelling left\n" ;

	}

	if (maze[row-1][col] == 'O'  && row>0 && FLAG != 'D') {
			//cout << "moving up\n" ;									//move up
		    result[row-1][col] = 1 ;
		    if(ratmaze2(n, m, row-1, col, 'U')) return true;
		    result[row-1][col] = 0;
			//cout << "cancelling up\n" ;

	}

    return false ;
}


int main(){
    result[0][0] = 1;

    int n,m ; cin >>n >>m ;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }


    if (ratmaze2(n, m, 0, 0,0)) {
        printresult(n, m);
    } else cout << "NO PATH FOUND\n" << endl ;


}
