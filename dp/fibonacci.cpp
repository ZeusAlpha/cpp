#include <bits/stdc++.h>
using namespace std;


int main()
{
	cout << "Please mention the number till where the fibonacci should be computed" << endl;
	int size;
	cin >> size;
	size++;
	vector <int> arr;
	for(int i=0;i<size;i++)
	{
		if(i==0) arr.push_back(0);
		else if(i==1) arr.push_back(1);
		else
		{
			int temp = arr[i-1] + arr[i-2];
			arr.push_back(temp);
		}
	}
	
	/*vector <int> :: iterator itr;
	for(itr=arr.begin(); itr!=arr.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;*/
	cout << arr[arr.size()-1] << endl;

	return 0;
}
