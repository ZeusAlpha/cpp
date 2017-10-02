#include <bits/stdc++.h>
using namespace std;

int do_magic(int n)
{
	vector<int> arr;
	int a=0,b=0,c=0;
	int z2=2,z3=3,z5=5;
	
	int output = 1;
	arr.push_back(output);
	
	for(int i=1;i<n;i++)
	{
		output = min(z2,min(z3,z5));
		arr.push_back(output);
		if(output==z2)
		{
			a+=1;
			z2=arr[a]*2;
		}
		if(output==z3)
		{
			b+=1;
			z3=arr[b]*3;
		}
		if(output==z5)
		{
			c+=1;
			z5=arr[c]*5;
		}
	}
	return output;	
}

int main()
{
	cout << "Please mention the number n to find the nth ugly number (div by 2,3,5)" << endl;
	int n;
	cin >> n;
	
	int output = do_magic(n);
	cout << output << endl;
	return 0;
}
