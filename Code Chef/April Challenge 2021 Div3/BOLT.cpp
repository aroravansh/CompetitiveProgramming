/*
There are mainly 3 important factors that result in the variation in speed during practice and during competition.
The first factor is a difference in track material which results in variation in the speed at competition with respect to practice by a factor of k1.
The second factor is wind speed which results in variation in the speed at competition with respect to practice by a factor of k2.
The final factor is the maximum speed achieved during practice. If the maximum speed during practice is v m/s then in competition it will be k3∗v m/s.
Given Chef's max speed v during practice and the factors k1,k2,k3, find whether he will be able to create a new world record, i.e, can he complete 100 m
in less than 9.58 seconds?
Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four floats k1,k2,k3,v.
Output:
Output in a single line, the answer, which should be "YES" if it's possible for Chef to create a new world record and "NO" if not.
Sample Input:
3
1.0 1.0 1.0 10.45
1.0 1.0 1.0 10.44
1.0 1.0 0.9 10.44
Sample Output:
YES
NO
NO
*/
#include <iostream>
using namespace std;
float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main() {
	int t;
	cin>>t;
	float ans;
	float k1,k2,k3,v;
	while(t--)
	{
	    cin>>k1>>k2>>k3>>v;
	    ans = 100/(k1*k2*k3*v);
	    ans = round(ans);
	    if(ans<=9.57)
	     cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	    
	}
	return 0;
}

