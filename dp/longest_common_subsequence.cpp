#include <bits/stdc++.h>
using namespace std;

int do_magic(string &s1, string &s2)
{
	int m= s1.length();
	int n= s2.length();
	int arr[m+1][n+1];
	for(int i=0; i<=m; i++) arr[i][0] = 0;
	for(int i=0; i<=n; i++) arr[0][i] = 0;
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(s1[i-1]==s2[j-1]) 
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}	
	return arr[m][n];
}

int main()
{
	cout << "Please mention the string 1" << endl;
	string s1,s2;
	cin >> s1;
	cout << "Please mention the string 2" << endl;
	cin >> s2;
	
	int answer = do_magic(s1,s2);
	cout << answer << endl;
	
	return 0;
}
