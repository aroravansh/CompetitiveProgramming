/*
There are n chocolates, and you are given an array of n numbers where the i-th number Ai is the flavour type of the i-th chocolate. Sebrina wants to eat as many different 
types of chocolates as possible, but she also has to save at least x number of chocolates for her little brother.
Find the maximum possible number of distinct flavour types Sebrina can have.
Input:
The first line contains an integer T --- the number of test cases.
The first line of each test case consists of two integers n, x - The number of chocolates Sabrina has and the number of chocolates she has to save for her brother, respectively.
The second line contains n integers A1,…,An, where the i-th chocolate has type Ai.
Output:
For each test case, output a single integer denoting the maximum possible number of distinct chocolate flavours Sabrina can eat
Sample Input:
3
2 1
1 2
4 2
1 1 1 1
5 3
50 50 50 100 100
Sample Output:
1
1
2
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[a[i]]+=1;
        int res = 0;
        for(auto it = mp.begin();it!=mp.end();it++){
            res += it->second-1;
        }
        if(res<x){
            cout<<mp.size()-x+res<<endl;
        }
        else{
            cout<<mp.size()<<endl;
        }
    }
}
