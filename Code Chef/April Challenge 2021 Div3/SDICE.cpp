/*
Chef has N 6-sided standard dice. Each die has dimensions 1×1×1. Since Chef is bored during the quarantine, he decides to stack dice for fun.
First, Chef forms four vertical stacks of dice (not necessarily with the same height; empty stacks are allowed) on his table, which together make up a pile of dice 
with base area up to 2×2. Among all such structures, the total visible surface area of Chef's structure must be the smallest possible.
Then, Chef calculates the number of pips on the visible faces of all dice in the structure. A face of a die is visible if it does not touch the table or another die.
Now, he is wondering: among all possible arrangements of dice, what is the maximum possible total number of visible pips? Since he is busy cooking, he is asking you 
to solve this.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing one integer ― the maximum possible number of visible pips.
Example Input
1
1
Example Output
20
*/
#include <iostream>
using namespace std;

int main() {
    long long t;
 cin>>t;
 while(t--)
 {
     long long n;
     cin>>n;
     if(n==1)
     {
         cout<<"20";
     }
     else if(n==2)
     {
         cout<<"36";
     }
     else if(n==3)
     {
         cout<<"51";
     }
     else
     {
         long long r=n%4;
         long long ans=((n-r)/4)*44;
         if(r==0)
         {
             ans+=16;
         }
         else if(r==1)
         {
             ans+=32;
         }
         else if(r==2)
         {
             ans+=44;
         }
         else if(r==3)
         {
             ans+=55;
         }
         cout<<ans;
     }
     cout<<endl;
 }
 return 0;
}
