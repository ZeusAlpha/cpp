#include <iostream>
using namespace std;

void increm(int *x)
{
	*x = *x + 1;
}

void increm(int x)
{
	x = x + 1;
}

int main()
{
	int x = 10;
	//call by ref
	increm(&x);
	cout << "The value of x is: " << x << endl;
	//call by value
	increm(x);
	cout << "The value of x is: " << x << endl;
	return 0;
}
