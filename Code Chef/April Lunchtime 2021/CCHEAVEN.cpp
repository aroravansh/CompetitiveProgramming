/*
When Chef was born, his parents took him to the famous monk Doctor Strange to know whether he will land himself in heaven after his life or not. According to Strange, 
Chef will live for L years in total. If he wants to go to heaven, he must spend at least 50% of his life years doing good deeds. He also shows them his future using a
string S of length L where Si=0 means the i-th year will be counted as bad as per the rule books of heaven and Si=1 means the i-th year will be counted as good.
Also, Strange can use his special powers to make Chef end his life earlier than that planned by god, i.e, he can choose some L′ (1≤L′≤L) and make him live for only
L′ years. Strange wants Chef to succeed, so if there is any choice of L′ that allows Chef to go to heaven, he will do so. Tell whether Chef can go to heaven.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains a single integer L.
The second line contains a string S of length L, consisting of symbols 0 and 1.
Output
For each test case, output the answer in a single line: "YES" if Chef can go to heaven and "NO" if not (without quotes).
Sample Input:
3
2
10
3
001
4
0100
Sample Output
YES
NO
YES
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--) {
	    long long l, x[2] = {0};
	    string s;
	    bool flag = false;
	    cin>>l>>s;
	    for (long long i=0; i<l; i++) {
	        if (s[i]=='1') x[1]++;
	        else x[0]++;
	        
	        if (x[1] >= x[0]) {
	            flag = true;
	            break;
	        }
	    }
	    //cout<<x[0]<<" "<<x[1]<<endl;
	    if (flag) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0;
}
