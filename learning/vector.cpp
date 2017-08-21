#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> alpha;
	vector <int> :: iterator itr;
	vector <int> :: reverse_iterator ritr;
	
	for(int i=0;i<4;i++)
	{
		alpha.push_back(i+1);
	}
	cout << "The contents of the vector are: " << endl;
	for(itr = alpha.begin(); itr!=alpha.end(); itr++)
	{
		cout << *itr << endl;
	}
	
	cout << endl; 
	
	for(ritr = alpha.rbegin(); ritr!=alpha.rend(); ritr++)
	{
		cout << *ritr << endl;
	}
	
	cout << endl; 
	
	//assign function 
	vector <int> beta;
	beta.assign(5,10);
	
	for(itr = beta.begin(); itr < beta.end() ; itr ++)
	{
		cout << *itr << endl;
	}
	
	//pop_back function
	cout << endl;
	cout << alpha.back() << endl;
	alpha.pop_back();
	cout << alpha.size() << ": This is the size after pop back" << endl;
	
	
	//erase function
	vector <double> gamma;
	for(int i=0;i<7;i++)
	{
		gamma.push_back(rand()%10);
	}
	
	vector <double> :: iterator itr1;
	
	cout << "These are the contents of gamma" << endl;
	for(itr1 = gamma.begin(); itr1 < gamma.end() ; itr1 ++)
	{
		cout << *itr1 << endl;
	}	
	
	gamma.erase(gamma.begin()+1,gamma.begin()+3);
	
	cout << "These are the contents of gamma after deletion of elements" << endl;
	for(itr1 = gamma.begin(); itr1 < gamma.end() ; itr1 ++)
	{
		cout << *itr1 << endl;
	}	
	
	return 0;
}
