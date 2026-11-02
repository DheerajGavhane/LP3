
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,W;

    cout<<"Enter number of items: ";
    cin>>n;

    int wt[n],val[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter weight and profit of item "<<i+1<<": ";
        cin>>wt[i]>>val[i];
    }

    cout<<"Enter knapsack capacity: ";
    cin>>W;

    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],
                    val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<"\nMaximum Profit: "<<dp[n][W]<<endl;

    cout<<"Selected Items: ";

    int j=W;

    for(int i=n;i>0;i--)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            cout<<i<<" ";
            j=j-wt[i-1];
        }
    }

    return 0;
}

/*
Dynamic Programming (DP) is an algorithmic technique used to solve complex problems by breaking them into smaller subproblems and storing their results to avoid repeated calculations.
Instead of solving the same subproblem multiple times, DP stores the previously calculated results in a table.
The 0/1 Knapsack problem is an optimization problem in which we are given:
- A knapsack with a fixed weight capacity.
- A set of items.
- Each item has a weight and a profit (value).
Our objective is to select items such that the total profit is maximum without exceeding the knapsack capacity.

The name 0/1 means:
- 1 means the item is selected completely.
- 0 means the item is not selected.
- We cannot select a fraction of an item.
Start.



Read the number of items n.
Read the weight and profit of each item.
Read the knapsack capacity W.
Create a DP table of size (n+1) × (W+1).
Initialize the first row and first column with zero.
For every item and capacity:
- If item weight is less than or equal to current capacity, calculate maximum of including and excluding the item.
- Otherwise, copy the value from the previous row.
Display the maximum profit stored in dp[n][W].
Trace the DP table to identify selected items.
Stop.
n = Number of items.
W = Knapsack capacity.
wt[i] = Weight of item i.
val[i] = Profit of item i.
dp[i][j] = Maximum profit using the first i items with capacity j.
O(nW) is called pseudo-polynomial time because it depends on the numerical value of capacity W, not just the number of bits needed to represent W.
Enter number of items: 4
Enter weight and profit of item 1: 3 2
Enter weight and profit of item 2: 4 3
Enter weight and profit of item 3: 6 1
Enter weight and profit of item 4: 5 4
Enter knapsack capacity: 8

Maximum Profit: 6
Selected Items: 4 1 
*/