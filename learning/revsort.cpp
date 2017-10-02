#include <bits/stdc++.h>
using namespace std;


int main()
{
	int arr[5] = {1,2,3,4,5};
	sort(arr,arr+3);
	reverse(arr,arr+3);
	cout << arr[0] << arr[1] << arr[2] << endl;
	return 0;
}
