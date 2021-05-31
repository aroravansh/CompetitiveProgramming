/*
After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.
On any regular day, Chef does N exercises at times A1,A2,…,AN (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN units. In the period between 
two consecutive exercises, his muscles relax R units of tension per minute.
More formally, Chef's tension is described by a number x. Before any workouts, x=0. When he does a workout at time Ai, the tension x instantly increases by Bi.
Between workouts, the number x decreases by R units per minute, maximized with 0.
Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.
Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains 3 lines of input.
The first line will contain 2 space-separated integers N,R, number of timestamps at which Chef performs his exercise, and units of tension relaxed per minute.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output:
For each testcase, output in a single line the maximum amount of tension Chef will have in his muscles.
Sample Input:
3
1 2
10
10
2 2
10 11
10 10
3 1
1 2 3
1 2 3
Sample Output:
10
18
4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T = 0;
	cin>>T;
	while(T--)
	{
	    long long int n,r;
	    cin>>n>>r;
	    long long int a[n],b[n];
	    for(long long int i=0;i<n;i++)cin>>a[i];
	    for(long long int j=0;j<n;j++)cin>>b[j];
	    long long int mx = b[0], tmp = b[0];
        long long int z = 0;
        for(int i = 1;i<n;i++){
            long long int x = a[i] - a[i-1];
            tmp = max(z,tmp - r*x);
            tmp += b[i];
            mx = max(mx,tmp);
        }
	    cout<<mx<<endl;
	}
	return 0;
}
