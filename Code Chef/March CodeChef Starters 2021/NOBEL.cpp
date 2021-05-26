/*
hef knows that the Nobel community is going to award the prize to that person whose research is different from others (ie. no other researcher should work on the same topic).
If there are multiple such people, who work on unique topics, then they will all share the prize. It might also happen that no one wins this time.
Chef also knows the N researchers which the community who will be considered for the prize, and the topics in which each of them work.
In total the CS field can be divided into M broad topics. Given the topics in which each of the N researchers are working on, in the form of an array A, and given that 
Chef can master any topic instantly, find whether he can win the prize. That is, can the Chef choose to work on some topic which will guarantee that he will win the prize? 
Chef doesn't mind sharing the prize with others.
Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of two lines of input.
First line contains two space separated integers N, M, number of researchers excluding Chef and total number of fields respectively.
Second line contains N space separated integers A1,A2,…AN, research topic of the researchers.
Output:
For each testcase, output in a single line answer, "Yes" if Chef can win the prize and "No" if not.
Sample Input:
3
4 4
1 2 3 4
5 4
4 2 1 1 1
4 4
4 4 4 4
Sample Output:
No
Yes
Yes
*/

#include <bits/stdc++.h>
using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			// store the elements in a set
			s.insert(x);
		}
		bool checker = false;
		for (int i = 1; i <= m; i++) {
			// check if every number up to 'm' is in the set
			if (s.find(i) == s.end()) {
				// if it's not, then set the 'checker' to true and end the loop
				checker = true;
				break;
			}
		}
		cout << (checker ? "Yes" : "No") << '\n';
	}
	return 0;
}
