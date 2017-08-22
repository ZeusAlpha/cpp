//This is for the object related testing in cpp
#include <bits/stdc++.h>
using namespace std;

class Alpha
{
public:
    int x;
    int y;
    int z;
    Alpha(int xx, int yx, int zx)
    {
        this->x = xx;
        this->y = yx;
        this->z = zx;
    }
};


int main()
{
    vector<int> vect;
    vect.push_back(1654);
    vect.push_back(121342);
    vector<int> :: iterator i;
    Alpha alpha(2,3,4);
    cout << alpha.y << endl;

    for(i = vect.begin(); i!=vect.end(); i++)
    {
        cout << *i << endl;
    }

    return 0;
}