#include <bits/stdc++.h>
using namespace std;

int do_magic(string s)
{
	int n = s.size();
	int dp[n][n];
	memset(dp,0,pow(n,2));
	
	for(int gap=1;gap<n;gap++)
	{
		for(int l=0,r=gap;r<n;l++,r++)
		{
			if(s[l]==s[r])
			{
				dp[l][r] = dp[l+1][r-1];
			}
			else
			{
				dp[l][r] = min(dp[l+1][r],dp[l][r-1]) + 1;
			}
		}
	}
	return dp[0][n-1];
}	


int main()
{
	cout << "Please mention the string for checking the minimum number of insertions to make it palindrome" << endl;
	
	string s;	
	cin >> s;
	
	cout << "The minimum insertions are: " << do_magic(s) << endl;	
	return 0;
}
