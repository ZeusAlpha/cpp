#include <iostream>
using namespace std;

class Alpha
{
	public:
		int value;
		void printValue();
};

void Alpha :: printValue()
{
	cout << "The value is: " << value << endl;
}


int main()
{
	Alpha alpha;
	alpha.value = 10;
	alpha.printValue();
	return 0;
}
