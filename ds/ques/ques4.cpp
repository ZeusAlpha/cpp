//Given an array containing both negative and 
//positive integers. Find the contiguous sub-array 
//with maximum sum.

#include <bits/stdc++.h>
using namespace std;

void getSolution(int arr[], int size)
{
    int output = arr[0];
    int temp = arr[0];
    for(int i=1;i<size;i++)
    {
        temp = max(arr[i],arr[i]+temp);
        output = max(temp,output);
    }
    cout << output << endl;
}


int main()
{
    int testcase,size;
    cin >> testcase;

    for(int i=0; i< testcase; i++)
    {
        cin >> size;
        int arr[size];

        for(int j=0;j<size;j++)
        {
            scanf("%d",&arr[j]);
        }

        //logic
        getSolution(arr,size);
    }

    return 0;
}