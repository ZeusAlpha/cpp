/*Given a string consisting of only 0, 1, A, B, C where
A = AND
B = OR
C = XOR
Calculate the value of the string assuming no order of precedence and evaluation is done from left to right.*/

#include<iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for(int i=0; i<testcase; i++)
	{
		string temp;
		cin >> temp;
		for(int j=0;j<temp.size();j++)
		{
			if(temp[j]=='A')
			{
				if(temp[j-1]=='0'||temp[j+1]=='0')
				{
					temp[j+1] = '0';
				}
				else
				{
					temp[j+1] = '1';
				}
			}
			else if(temp[j]=='B')
			{
				if(temp[j-1]=='1'||temp[j+1]=='1')
				{
					temp[j+1] = '1';
				}
				else
				{
					temp[j+1] = '0';
				}
			}
			else if(temp[j]=='C')
			{
				if(temp[j-1]==temp[j+1])
				{
					temp[j+1] = '0';
				}
				else
				{
					temp[j+1] = '1';
				}
			}
		}
		cout << temp[-1] << endl;		
	}
	return 0;
}
