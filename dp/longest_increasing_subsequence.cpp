#include <bits/stdc++.h>
using namespace std;

int do_magic(int arr[])
{
	int n = 7;
	int lis[n];
	for(int i=0;i<7;i++) lis[i] = 1;
	
	for(int end=1; end<n; end++)
	{
		for(int start=0;start<end;start++)
		{
			if(arr[start] < arr[end] && lis[end] < lis[start] + 1)
			{
				lis[end] = lis[start] + 1; 
			}
		}
	}
	
	int answer = 0;
	for(int i=0;i<n;i++)
	{
		if(answer < lis[i])
		{
			answer = lis[i];
		}
	}
	
	return answer;
}

int main()
{
	int arr[] = {2,3,5,1,4,7,6};
	cout << "The length of the longest increasing subsequence is: " << do_magic(arr) << endl;	
	return 0;
}
