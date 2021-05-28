/*
A string is said to be using strong language if it contains at least K consecutive characters '*'.
You are given a string S with length N. Determine whether it uses strong language or not.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains a single string S with length N.
Output
Print a single line containing the string "YES" if the string contains strong language or "NO" if it does not (without quotes).
Example Input
3
5 2
*a*b*
5 2
*a**b
5 1
abcde
Example Output
NO
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    int k;
	    cin>>n>>k;
	    string str;
	     cin.ignore(numeric_limits<streamsize>::max(),'\n');
	     getline(cin , str);
	     
	     int c=0;
	     for(int i = 0; i<n ;i++){
	         if(str[i]=='*'){
	            c++;
	         }else{
	             if(c==k){
	                 break;
	             }else{
	               c=0;  
	             }
	             
	         }
	     }
	     if(c==k){
	         cout<<"YES"<<endl;
	     }else{
	         cout<<"NO"<<endl;
	     }
  }
	return 0;
}
