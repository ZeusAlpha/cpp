#include <bits/stdc++.h>
using namespace std;

int lcsub(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();
	
	int dp[m+1][n+1];
	
	int output =0;
	
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0||j==0) dp[i][j] = 0;
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				output = max(output, dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return output;
}


int main()
{
	
	cout << "Please mention the string 1" << endl;
	string s1;
	cin >> s1;
	
	cout << "Please mention the string 2" << endl;
	string s2;
	cin >> s2;
	
	cout << "The length of the largest common substring is: " << lcsub(s1,s2);
	
	return 0;
}
