#include <bits/stdc++.h>
using namespace std;

int do_magic(string &s1, string &s2)
{
	int m = s1.length();
	int n = s2.length();
	
	int dp[m+1][n+1];
	
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];
			
			else
			{
				dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
			}
		}
	}
	return dp[m][n];
}

int main()
{
	cout << "Mention the string 1" << endl;
	string s1;
	cin >> s1;
	cout << "Mention the string 2" << endl;
	string s2;
	cin >> s2;
	
	cout << "The min distance to convert one string to other is: " << do_magic(s1,s2) << endl;
	return 0;
}
