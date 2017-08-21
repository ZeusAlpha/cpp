#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	pair<int,int> alpha (1,2);
	cout << alpha.first << " " << alpha.second << endl;
	pair<int,int> beta (3,4);
	cout << beta.first << " " << beta.second << endl;
	alpha.swap(beta);
	cout << alpha.first << " " << alpha.second << endl;
	cout << beta.first << " " << beta.second << endl;
	return 0;
}
