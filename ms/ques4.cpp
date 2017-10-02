/*Given an array of integers (both odd and even), sort them in such a way that the first part of the array contains odd numbers sorted in descending order, rest portion contains even numbers sorted in ascending order.
Examples:
Input  : arr[] = {1, 2, 3, 5, 4, 7, 10}
Output : arr[] = {7, 5, 3, 1, 2, 4, 10}
Input  : arr[] = {0, 4, 5, 3, 7, 2, 1}
Output : arr[] = {7, 5, 3, 1, 0, 2, 4} */

#include <bits/stdc++.h>
using namespace std;

void partition(int arr[],int size)
{
	int odd = 0;
	int even = size-1;
	while(odd<even)
	{
		if(arr[odd]%2==1 && arr[even]%2==0)
		{
			odd ++;
			even ++;
		}
		else if(arr[odd]%2==0 && arr[even]==0)
		{
			while(arr[even]%2!=1 && odd < even) even --;
			
		}
		else if(arr[odd]%2==1 && arr[even]==1)
		{
			while(arr[odd]%2!=0 && odd < even) odd ++;
			
		}
		else
		{
			int temp = arr[odd];
			arr[odd] = arr[even];
			arr[even] = temp;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	
	for(int i=0;i<tc;i++)
	{
		int size;
		cin >> size;
		int arr[size];
		for(int j=0;j<size;j++)
		{
			int temp;
			cin >> temp;
			arr[j] = temp;
		}
		cout << "sfsfsfs ";
		partition(arr,size);
		/*int pos = 0;
		while(arr[pos]%2!=0) pos++;
		sort(arr,arr + pos-1);
		sort(arr+pos,arr+size-1);*/
		for(int j=0;j<size;j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
