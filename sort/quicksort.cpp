#include <bits/stdc++.h>
using namespace std;

int partiton(vector <int> &arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for(int j=low; j <=high-1; j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}


void quickSort(vector <int> &arr, int low, int high)
{
	if(low < high)
	{
		int pi = partiton(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}


int main()
{
	int size;
	cin >> size;
	vector <int> arr;
	for(int i=0;i<size;i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	quickSort(arr,0,size-1);
	cout << "The sorted array is: " << endl;
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
