//Write a program to find the majority element in the 
//array. A majority element in an array A[] of size n is 
//an element that appears more than n/2 times 
//(and hence there is at most one such element).  If input 
//array doesn't contain a majority element, then output
// "NO Majority Element"



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int i=0;i<testcases;i++)
    {
        int hash1[101];
        for(int k=0;k<101;k++)
        {
            hash1[k]=0;
        }
        int size;
        cin >> size;
        bool found = false;
        int ans;
        for(int j=0;j<size;j++)
        {
            int temp;
            cin >> temp;
            int alpha = hash1[temp];
            alpha+=1;
            hash1[temp] = alpha;
            if(alpha>size/2)
            {
                found = true;
                ans = temp;
            }
        }
        if(found==false)
        cout << "NO Majority Element" << endl;
        else
        cout << ans << endl;
    }

    return 0;
}