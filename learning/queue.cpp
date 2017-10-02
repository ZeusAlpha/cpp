#include <bits/stdc++.h>
using namespace std;


int main()
{
	queue <int> alpha;
	alpha.push(10);
	alpha.push(20);
	alpha.push(30);
	cout << alpha.front() << endl;
	cout << alpha.back() << endl;
	alpha.pop();
	cout << alpha.front() << endl;
	cout << alpha.back() << endl;
	alpha.push(80);
	cout << alpha.front() << endl;
	cout << alpha.back() << endl;
	return 0;
}
