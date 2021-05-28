/*
You are given a binary string S. Chef defines MEX(S) as the smallest non-negative integer such that its binary representation (without leading '0'-s; in particular, 
the binary representation of 0 is "0") is not a subsequence of S.
Chef is asking you to find MEX(S). Since this integer could be very large, find its binary representation (without leading '0'-s).
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.
Output
For each test case, print a single line containing one string: MEX(S) in binary representation.
Sample Input
2
1001011
1111
Example Output
1100
0 
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        long long n=s.length();
        long long next0[n],next1[n],arr[n+2],arr1[n+2];
        int last_pos=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                for(int j=last_pos+1;j<=i;++j)
                    next0[j]=i;
                last_pos=i;
            }
        }
        for(int i=last_pos+1;i<n;++i)
            next0[i]=n;
        if(next0[0]==n)
            cout<<"0"<<endl;
        else{
        last_pos=-1;
        for(int i=0;i<n;++i){
            if(s[i]=='1'){
               for(int j=last_pos+1;j<=i;++j)
                   next1[j]=i;
               last_pos=i;
            }
        }
        for(int i=last_pos+1;i<n;++i)
            next1[i]=n;
        arr[n]=arr[n+1]=0;
        arr1[n]=arr1[n+1]=0;
        for(int i=n-1;i>=0;--i){
            arr[i]=arr[i+1];
            if(s[i]=='0'&&next1[i]<n)
                arr[i]=max(arr[i],arr[next1[i]+1]+1);
            if(s[i]=='1'&&next0[i]<n)
                arr[i]=max(arr[i],arr[next0[i]+1]+1);
            arr1[i]=arr1[i+1];
            if(next1[i]<n)
                arr1[i]=max(arr1[i],arr[next1[i]+1]+1);
        }
        int len=arr1[0]+1;
        int op=next1[0]+1;
        string res="1";
        for(int i=1;i<len;++i){
            if(op>=n){
                res+='0';
                continue;
            }
            if(next0[op]>=n){
                res+='0';
                op=next0[op]+1;
                continue;
            }
            if(arr[next0[op]+1]<len-i-1){
                res+='0';
                op=next0[op]+1;
            }else{
                res+='1';
                op=next1[op]+1;
            }
        }
        cout<<res<<endl;
        }
    }
    return 0;
}
