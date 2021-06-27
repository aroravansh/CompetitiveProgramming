/*
Chef is planning a heist in the reserve bank of Chefland. They are planning to hijack the bank for D days and print the money. The initial rate of printing the currency 
is P dollars per day and they increase the production by Q dollars after every interval of d days. For example, after d days the rate is P+Q dollars per day, 
and after 2d days the rate is P+2Q dollars per day, and so on. Output the amount of money they will be able to print in the given period.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers D,d,P,Q.
Output
For each test case, output in a single line the answer to the problem.
Sample Input
3
2 1 1 1
3 2 1 1
5 2 1 2
Sample Output
3
4
13
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i =a;i<b;i++)
//const ll m = 1000000007;

void solve()
{
    ll D,d,p,q,ans,c=0;
    cin>>D>>d>>p>>q;
    ll n = D/d;
    ans = n*p*d + (q*(n*(n-1))/2)*d +(D%d)*(p+n*q);
    cout<<ans<<"\n";
    
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
