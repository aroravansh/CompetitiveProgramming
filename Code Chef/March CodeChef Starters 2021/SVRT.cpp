/*
You are the Chief Engineer of a fast growing start-up. You wish to place K servers in some distinct locations from among N locations. The locations, numbered 1,2,…,N 
are arranged in a circular manner. The distance between every adjacent location is 1 unit. 1 and N are adjacent.
You want to place the servers such that the maximum shortest distance between any two adjacent servers is as less as possible. Find this minimum possible distance that 
can be achieved, and also the minimum number of pairs of adjacent servers separated by this distance.
Input:
The first line contains a single integer, T, denoting the number of test cases.
Each test case consists of a single line containing two space-separated integers N and K, denoting the number of locations, and the number of servers, respectively.
Output:
For test case, output two space-separated integers D and X, denoting the minimum possible maximum shortest distance that can be achieved between any two adjacent servers, 
and the minimum number of pairs of servers separated by this distance, respectively, in a separate line.
Sample Input:
3
6 3
10 6
10 4
Sample Output:
2 3
2 4
3 2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long int n,k,y,x;
	cin>>t;
	float c;
	while(t--)
	{
	    cin>>n>>k;
	    c = ((float)(n))/k;
	    x = ceil(c);
	    cout<<x<<" ";
	    y = n%k;
	    if(y!=0)
	     cout<<y;
	    else if(y==0)
	    {
	        cout<<k;
	    }
	    cout<<endl;
	    
	}
	return 0;
}
