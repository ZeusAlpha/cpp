#include <bits/stdc++.h>
using namespace std;

int do_magic(vector<int> val, vector<int> wt, int W )
{
	int n = val.size();
	int dp[n+1][W+1];
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=W; j++)
		{
			if(i==0||j==0) dp[i][j] = 0;
			else if(wt[i-1]<W)
			{
				dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),(dp[i-1][j]));
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][W];	
}


int main()
{
	
	vector<int> val {60, 100, 120};
	vector<int> wt {10, 20, 30};
	int W = 50;
	cout << "The max value of the knapsack is: " << do_magic(val,wt,W) << endl;	
	
	return 0;
}
