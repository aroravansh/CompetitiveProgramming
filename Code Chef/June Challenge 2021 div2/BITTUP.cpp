/*
Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2M−1 and A1&A2&…&AN=0, where & denotes the bitwise AND operator.
Since the number of tuples can be large, output it modulo 109+7.
Input
The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers N and M.
Output
For each test case, output in a single line the answer to the problem modulo 109+7.
Sample Input
4
1 2
2 2
4 2
8 4
Sample Output
1
9
225
228250597
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i =a;i<b;i++)
const ll m = 1000000007;

ll binpow(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
void solve()
{
    ll n,k,a,b;
    cin>>n>>k;
    a=binpow(2,n);
    a--;
    b=binpow(a,k);
    cout<<b<<"\n";
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
