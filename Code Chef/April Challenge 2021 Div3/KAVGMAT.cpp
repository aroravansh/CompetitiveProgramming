/*
Chef found a matrix A with N rows (numbered 1 through N) and M columns (numbered 1 through M), where for each row r and column c, the cell in row r and column c 
(denoted by (r,c)) contains an integer Ar,c. This matrix has two interesting properties:
The integers in each row form a non-decreasing sequence, i.e. for each valid i, Ai,1≤Ai,2≤…≤Ai,M.
The integers in each column also form a non-decreasing sequence, i.e. for each valid j, A1,j≤A2,j≤…≤AN,j.
A K-worthy submatrix is a square submatrix of A, i.e. a submatrix with l rows and l columns, for any integer l, such that the average of all the integers in this 
submatrix is ≥K. Chef wants you to find the number of K-worthy submatrices of A.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and K.
N lines follow. For each valid i, the i-th of these lines contains M space-separated integers Ai,1,Ai,2,Ai,3,…,Ai,M.
Output
For each test case, print a single line containing one integer ― the number of K-worthy submatrices of A.
Example Input
1
3 3 4
2 2 3
3 4 5
4 5 5
Example Output
7
*/
#include <bits/stdc++.h>
using namespace std;

long long int a(long long int x, long long int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, k;
        cin >> n >> m >> k;
        double arr[n + 1][m + 1];
        for (long long int i = 0; i <= n; i++)
        {
            for (long long int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    cin >> arr[i][j];
                }
            }
        }

        for (long long int i = 0; i <= n; i++)
        {
            double temp = 0;
            for (long long int j = 0; j <= m; j++)
            {
                arr[i][j] = arr[i][j] + temp;
                temp = arr[i][j];
            }
        }
        for (long long int j = 0; j <= m; j++)
        {
            double temp = 0;
            for (long long int i = 0; i <= n; i++)
            {
                arr[i][j] = arr[i][j] + temp;
                temp = arr[i][j];
            }
        }
        long long int max_order = a(n, m);
        long long int ans = 0;
        for (long long int order = 1; order <= max_order; order++)
        {
            for (long long int j = order; j <= n; j++)
            {
                for (long long int l = order; l <= m; l++)
                {
                    if ((arr[j][l] + arr[j - order][l - order] - arr[j - order][l] - arr[j][l - order]) / (order * order) >= k)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
