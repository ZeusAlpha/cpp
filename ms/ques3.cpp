/*Rearrange a given array in-place such that all the negative 
numbers occurs before positive numbers.(Maintain the order 
of all -ve and +ve numbers as given in the original array).*/

#include <iostream>
#include <vector>
using namespace std;

void partition(vector <int> &arr,int size)
{
	int pos=0;
	int posi=0,neg=0;
	for(int i = 0;i<size; i++)
	{
	    if(arr[i]>=0) posi ++;
	    else neg ++;
	}
	if(posi!=0 && neg != 0)
	{
	    for(int i=0;i<size;i++)
    	{
    		if(arr[pos]>=0 && arr[i] < arr[pos])
    		{
    			pos = i;
    		}
    	}
    	int pivot = arr[pos];
    	for(int j=0; j<size; j++)
    	{
    	    if(pos>=j)
    	    {
    	        if(arr[j]>pivot)
    	        {
    	            swap(arr[j],arr[pos]);
    	            pos = j;
    	            pivot = arr[pos];
    	        }
    	    }
    	    else
    	    {
    	        if(arr[j]<pivot)
    	        {
    	            swap(arr[j],arr[pos]);
    	            pos = j;
    	            pivot = arr[pos];
    	        }
            }
	    
	    }
	}
	
}


int main()
{
	int testcase;
	cin >> testcase;
	for(int i=0; i<testcase; i++)
	{
		int temp;
		cin >> temp;
		vector <int> arr;
		for(int j=0; j<temp; j++)
		{
			int alpha;
			cin >> alpha;
			arr.push_back(alpha);
		}
		partition(arr,temp);
		for(int j=0;j<temp; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		
	}
	return 0;
}
