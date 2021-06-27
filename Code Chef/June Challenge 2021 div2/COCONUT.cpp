/*
Chefland has 2 different types of coconut, type A and type B. Type A contains only xa milliliters of coconut water and type B contains only xb grams of coconut pulp. 
Chef's nutritionist has advised him to consume Xa milliliters of coconut water and Xb grams of coconut pulp every week in the summer. Find the total number of coconuts 
(type A + type B) that Chef should buy each week to keep himself active in the hot weather.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers xa, xb, Xa, Xb.
Output
For each test case, output in a single line the answer to the problem.
Sample Input
3
100 400 1000 1200
100 450 1000 1350
150 400 1200 1200
Sample Output
13
13
11
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//const ll m = 1000000007;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<(c/a)+(d/b)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
