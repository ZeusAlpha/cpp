//Given an array of size n-1 and given that there are 
//numbers from 1 to n with one missing, the missing 
//number is to be found.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    
    for(int i=0;i<testcases;i++)
    {
        int size;
        cin >> size;
        int sum = size*(size+1)/2;
        for(int j=0;j<size-1;j++)
        {
            int k;
            cin >> k;
            sum -= k;
        }
        cout << sum << endl;
    }

    return 0;
}