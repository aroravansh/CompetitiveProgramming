/*
There is only 1 TV in the common room, and as luck would have it, both the El Clasico football match and the India-Pakistan cricket match are happening simultaneously.
There is one football fan who is looking at the live commentary online and will scream whenever an 'important' event takes place in the El Clasico. Similarly, there is a 
cricket fan who will do so for every important event in the cricket match.
You are given two arrays - F1,F2,…,Fn, which denote the times when an important event happens in the football match. And similarly C1,C2,…,Cm for cricket. You sadly have 
the remote in hand. You start out by watching the El Clasico. But whenever an Important event happens in the sport which isn't on the TV right now, you will be forced to 
switch to that sport's channel, and this continues, i.e., you switch channels if and only if when an important event in the other sport happens. Find the total number of 
times you will have to switch between the channels.
Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of 3 lines of input.
First line contain 2 space separated integers N and M, number of important events in football and cricket match respectively.
Second line contain N space separated integers Fi, where the ith index represents ith important event in the football match.
Third line contain M space separated integers Ci, where the ith index represents ith important event in the cricket match.
Output:
For each testcase, output in a single line answer to the problem.
Sample Input:
3
2 2
1 3
2 4
3 1
100 200 300
1
1 2
1
100 200
Sample Output:
3
2
1
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
		vector<int> all_matches;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
			all_matches.emplace_back(x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			all_matches.emplace_back(x);
		}
		sort(all_matches.begin(), all_matches.end());
		string sequence = "f";
		for (int i = 0; i < (int) all_matches.size(); i++) {
			if (s.find(all_matches[i]) != s.end()) {
				sequence += "f";
			} else {
				sequence += "c";
			}
		}
		int cnt = 0;
		for (int i = 0; i < (int) sequence.size() - 1; i++) {
			// count the number of times that the current letter is different from the next 
			// letter (this will be the number of times that it switched)
			if (sequence[i] != sequence[i + 1]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
