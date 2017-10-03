#include <bits/stdc++.h>
using namespace std;

int do_magic(string s)
{
	
	int n = s.size();
	int dp[n][n];
	
	for(int i=0;i<n;i++)
	{
		dp[i][i] = 1;
	}
	
	for(int gap=2; gap<=n; gap++)
	{
		for(int start=0; start<(n-gap+1); start++)
		{
			int end = start + gap - 1;
			if(s[start]==s[end] && gap==2)
			{
				dp[start][end] = 2;
			}
			else if(s[start] == s[end])
			{
				dp[start][end] = dp[start+1][end-1] + 2;
			}
			else
			{
				dp[start][end] = max(dp[start][end-1], dp[start+1][end]);
			}
		}
	}
	
	return n-dp[0][n-1]; 
}


int main()
{
	cout << "Please mention the string for the solution" << endl;
	string s;
	cin >> s;
	
	cout << "The minimum number of deletions to form a palindrome is/are: " << do_magic(s) << endl;
	return 0;
}
