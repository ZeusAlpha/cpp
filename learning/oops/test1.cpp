
//By default member functions and variables are private

#include <iostream>
using namespace std;

class Alpha
{
	public :
		int i;
		void display()
		{
			cout << "The value of i is: " << i << endl;
		}
};



int main()
{
	Alpha alpha;
	alpha.i = 10;
	alpha.display();
}
