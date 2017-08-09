//K largest element from a given big array

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	int i;
	for(i=0;i<testcases;i++)
	{
		priority_queue <int> pq;
		int size;
		cin >> size;
		int limit;
		cin >> limit;
		int j;
		for(j=0;j<size;j++)
		{
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		for(j=0;j<limit;j++)
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
	
}
