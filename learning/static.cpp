#include <iostream>
using namespace std;

void func()
{
	static int i = 10;
	i+=1;
	cout << "The value of i is: " << i << endl;
}


int main()
{
	func();
	func();
	func();
	return 0;
}
