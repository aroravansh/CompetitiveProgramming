/*
You are given an array A with N integers. An array's score is defined as the bitwise AND of all its elements. You need to find the bitwise OR of the scores of all 
possible non-empty subarrays of A. Furthermore, there are Q queries. Each query consists of two integers X and V. You need to change the value of the element at index 
X to V. After each query, you again need to find the bitwise OR of the scores of all possible non-empty subarrays.
Input:
The first line of the input contains a single integer T - the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q - the size of the array and the number of queries, respectively.
The second line contains N space-separated integers A1,…,AN.
Each of the next Q lines contains two space-separated integers X and V - the position and the new value of the query, respectively.
Output:
For each test case print Q+1 lines. In the first line print the answer for the original array and in the next Q lines print the answer after every query.
Sample Input:
2
3 2
1 2 3
1 4
3 0
4 1
1 2 3 4
4 0
Sample Output:
3
7
6
7
3
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    int t;cin>>t;
    while(t--){
        ll n,q;cin>>n>>q;
        ll a[n];
        for(int i = 0;i<n;i++)
            cin>>a[i];
        int dp[31] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                ll x = 1<<j;
                if(a[i]&x)
                    dp[j] += 1;
            }
        }
        ll ans = 0;
        for(int i=0;i<31;i++){
            ll x = 1<<i;
            if(dp[i])
                ans += x;
        }
        cout<<ans<<endl;
        for(int k=0;k<q;k++){
            ll idx,val;
            cin>>idx>>val;
            for(int i=0;i<31;i++){
                ll x=1<<i;
                if(a[idx-1]&x){
                    dp[i] -= 1;
                }
            }
            for(int i=0;i<31;i++){
                ll x = 1<<i;
                if(val&x){
                    dp[i] += 1;
                }
            }
            a[idx-1] = val;
            ll ans = 0;
            for(int i=0;i<31;i++){
                ll x = 1<<i;
                if(dp[i]>0)
                    ans += x;
            }
            cout<<ans<<endl;
        }
    }
}
