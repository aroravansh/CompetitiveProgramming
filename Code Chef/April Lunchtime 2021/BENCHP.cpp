/*
In the gym, Chef prefers to lift at least W grams during a bench press and if that's impossible, Chef considers his workout to be incomplete and feels bad.
The rod weighs Wr grams and there are N other weights lying on the floor that weigh w1,w2,...,wN grams. To maintain balance and to ensure that there is no unnecessary 
load due to torque, it's important that the weights added to the left side are symmetric to the weights added to the right side. It is not required to use all of the weights.
It is also not required to use any weights at all, if Chef feels satisfied lifting only the rod.
For example:
1 2 2 1 |Rod Center| 1 1 1 3 is a wrong configuration, but
1 2 3 1 |Rod Center| 1 3 2 1 is a right configuration.
Find whether Chef will be able to collect the required weights to feel satisfied.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains three space-separated integers N,W,Wr.
The second line contains N space-separated integers w1,w2,…,wN.
Output
For each test case, output the answer in a single line: "YES" if Chef will be satisfied after his workout and "NO" if not (without quotes).
Sample Input
3
2 5 10 
2 2
7 100 50
100 10 10 10 10 10 90 
6 100 40 
10 10 10 10 10 10
Sample Output
YES
NO
YES
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w,wr;
        cin>>n>>w>>wr;
        map<int,int>mp;
        int Ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>Ar[i];
            mp[Ar[i]]++;
        }
        if(wr>=w)
        {
            cout<<"YES"<<"\n";
        }
        else{
            w -=wr;
            for(int i=0;i<n;i++)
            {
                if(mp[Ar[i]]>=2)
                {
                    int count = mp[Ar[i]];
                    if(count%2==0)
                    {
                        w-= count * Ar[i];
                    }
                    else
                    {
                        w-=(count-1)*Ar[i];
                    }
                    mp[Ar[i]]=0;
                }
                if(w<=0)
                {
                    break;
                }
            }
            if(w<=0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
