//This is the implementation of a heap sort
#include <iostream>
using namespace std;

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i+1;
}


int right(int i)
{
	return 2*i+2;
}

void max_heapify(int arr[], int size, int pos)
{
	int l,r;
	l = left(pos);
	r = right(pos);
	int largest;
	if(l<size && arr[l]>arr[pos])
	{
		largest = l;
	}
	else
	{
		largest = pos;
	}
	if(r<size && arr[r]>arr[largest])
	{
		largest = r;
	}
	if(largest!=pos)
	{
		int temp;
		temp = arr[pos];
		arr[pos] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,size, largest);
	}
}

void build_max_heap(int arr[], int size)
{
	int i;
	for(i=size/2-1;i>=0;i--)
	{
		max_heapify(arr, size, i);
	}
}


void heapsort(int a[], int size)
{
	build_max_heap(a,size);
	int i;
	for(i=size-1;i>0;i--)
	{
		int temp;
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		size = size - 1;
		cout << a[i] << endl;
		max_heapify(a,size,0);
	}
	cout << a[0] << endl;
}

int main()
{
	cout << "Please mention the number of elements in the array" << endl;
	int size;
	cin >> size;
	int i;
	int arr[size];
	cout << "Please mention the elements" << endl;
	for(i=0;i<size;i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	
	cout << "-----------------------" << endl;
	heapsort(arr,size);
	/*for(i=0;i<size;i++)
	{
		cout << arr[i] << endl;
	}*/
	return 0;
}
