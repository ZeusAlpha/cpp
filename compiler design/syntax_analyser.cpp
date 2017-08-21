#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;



int main()
{
	ifstream fin("tokens.txt");
	char str[255];
	vector <string> tokens;
	while(fin)
	{
		fin.getline(str,255);
		tokens.push_back(string(str));
	}
	return 0;
}
