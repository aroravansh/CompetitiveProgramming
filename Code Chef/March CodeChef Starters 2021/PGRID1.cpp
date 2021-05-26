/*
Suppose we have a 2D grid A of infinite width and height of N units. Each row of the grid can be represented in the form of 111…100…∞ where the 1s are repeated x times,
x>0. Implying that the row starts with x consecutive 1-s followed by all 0-s.
Initially all cells are unmarked. Cell (i,j) refers to the i-th row, and j-th column. (1,1) refers to the bottom-left cell.
Now you do the following in each step.
Choose an unmarked cell having 1. Let it be (i, j).
while((i,j) lies in the grid boundaries && A[i][j] == 1){
    mark[i][j] = true; i--; j--;
}
How many minimum number of steps are required to mark all the cells containing 1?
Note: The number of consecutive 1-s at each height is given by the array W where Wi represents the same at ith row.
Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contain 2 lines of input.
First line will contain N, height of the grid (number of rows).
Second line contains N space separated integers where ith index represents number of consecutive 1-s at the beginning of row i.
Output:
For each testcase, output in a single line answer to the problem.
Sample Input:
3
3
1 1 1
3
5 3 2
3
4 2 5
Sample Output:
3
7
8
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i=0; i<n; i++) cin>>a[i];

        long long ans1=0;

        ans1 += a[n-1];

        for(int i=n-1; i>0; i--)
        {
            if(a[i]<=a[i-1])
            {
                ans1 += a[i-1]-a[i]+1;
            }
        }

        long long ans2=0;

        ans2 += a[0];

        for(int i=0; i<n-1; i++)
        {
            if(a[i+1]<=a[i])
            {
                ans2++;
            }
            else
            {
                ans2+=a[i+1]-a[i];
            }
        }

        cout << min(ans1, ans2) << endl;
    }

    return 0;
}
