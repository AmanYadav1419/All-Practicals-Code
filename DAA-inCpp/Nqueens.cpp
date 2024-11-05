#include <bits/stdc++.h>
using namespace std;

int COL;
int ROW;
int N=4;

void printSolution(vector<vector<int>>board)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}


bool isSafe(vector<vector<int>>board, int row, int col)
{
	int i, j;

	
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

    //Added logic for first queen placed
    for (i = col+1; i < N; i++)
		if (board[row][i])
			return false;

    //Added logic for first queen placed
	for (i = row, j = col; i < N && j < N; i++, j++)
		if (board[i][j])
			return false;
            
    //Added logic for first queen placed
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
		if (board[i][j])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


bool solveNQUtil(vector<vector<int>>&board, int col)
{
	
	if (col >= N)
		return true;

	if(col==COL){
        if (solveNQUtil(board, col + 1))
				return true;
        else{
            return false;
        }
    }

    else{

	for (int i = 0; i < N; i++) {
		
		if (isSafe(board, i, col)) {
			
			
			board[i][col] = 1;

			
			if (solveNQUtil(board, col + 1))
				return true;

			
			board[i][col] = 0;
		}
	}
}

	
	return false;
}


bool solveNQ()
{
    cout<<"Enter size of board: ";
    cin>>N;
    cout<<"Enter row and col of first queen to be placed:\nrow: ";
    cin>>ROW;
    cout<<"\ncol: ";
    cin>>COL;
    cout<<endl;
	vector<vector<int>>board(N,vector<int>(N,0));


    board[ROW][COL]=1;


	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}


int main()
{
	solveNQ();
	return 0;
}

