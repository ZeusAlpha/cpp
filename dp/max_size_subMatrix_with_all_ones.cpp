#include <bits/stdc++.h>
using namespace std;

int do_magic(int r, int c, vector<vector<int> > &arr)
{
	int output = 0;
	int a[r][c];
	
	for(int i=0;i<r;i++) a[i][0] = arr[i][0];
	for(int j=0;j<c;j++) a[0][j] = arr[0][j];
	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(arr[i][j]==1)
			{
				a[i][j] = min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1]));
				if(a[i][j]>output) output = a[i][j];
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}	
	return output;
}


int main()
{
	
	cout << "Please mention the number of rows in the array" << endl;
	int r;
	cin >> r;
	cout << "Please mention the number of coloumns in the array" << endl;
	int c;
	cin >> c;
	
	vector<vector<int> > arr(r,vector<int>(c));
	
	for(int i=0; i<r;i++)
	{
		for(int j=0; j<c; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	cout << do_magic(r,c,arr) << endl;	
	
	
	return 0;
}
