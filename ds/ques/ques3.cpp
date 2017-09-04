//Given a binary number,  write a program that 
//prints 1 if given binary number is a 
//multiple of 3.  Else prints 0. The given
// number can be big upto 2^100

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int testcases;
    cin >> testcases;
    for(int i=0; i< testcases; i++)
    {
        string s;
        int sum=0;
        cin >> s;
        bool isEven = false;
        for(char &c : s)
        {
            if(isEven)
            {
                sum += (int)c - 48;
            }
            else
            {
                sum -= (int)c -48;
            }
            isEven = !isEven;
        }
        if(sum%3==0)
        cout << 1 << endl;
        else
        cout << 0 << endl;
    }
    return 0;
}