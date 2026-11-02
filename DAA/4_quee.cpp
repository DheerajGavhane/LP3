
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board,int row,int col,int n)
{
    // Check column
    for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
            return false;
    }

    // Check upper-left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
            return false;
    }

    // Check upper-right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board,int row,int n)
{
    if(row==n)
        return true;

    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]='Q';

            if(solve(board,row+1,n))
                return true;

            board[row][col]='.';
        }
    }

    return false;
}

int main()
{
    int n;

    cout<<"Enter board size: ";
    cin>>n;

    if(n<=0)
    {
        cout<<"Invalid board size";
        return 0;
    }

    vector<vector<char>> board(n,vector<char>(n,'.'));

    if(solve(board,0,n))
    {
        cout<<"Final N-Queens Matrix:\n";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";

            cout<<endl;
        }
    }
    else
    {
        cout<<"No solution exists.";
    }

    return 0;
}

/*
The N-Queens problem is a classic problem in which N Queens must be placed on an N × N chessboard such that no two Queens attack each other.
Queens must not share the same:
1. Row
2. Column
3. Diagonal
Backtracking is an algorithmic technique that builds a solution step by step. Whenever a choice cannot lead to a valid solution, it abandons that choice and tries another one.
3. Algorithm
1. Start.
2. Read the value of N.
3. Create an N × N chessboard initialized with 0.
4. Place the first Queen at the specified row and column.
5. Check whether the first Queen's position is valid.
6. Start placing Queens from the next row.
7. For each column, check whether the position is safe:
   - No Queen should exist in the same column.
   - No Queen should exist in the upper-left diagonal.
   - No Queen should exist in the upper-right diagonal.
8. If the position is safe, place the Queen and recursively process the next row.
9. If no position works, remove the Queen and backtrack.
10. If all N Queens are placed, print the chessboard.
11. Stop.
9. Applications of Backtracking
1. N-Queens problem.
2. Sudoku solver.
3. Maze solving.
4. Graph coloring.
Time Complexity: Approximately O(N! × N²) for this implementation because each safety check scans the board and backtracking explores possible arrangements.
Space Complexity: O(N²) for the chessboard, plus O(N) recursion stack space.
*/