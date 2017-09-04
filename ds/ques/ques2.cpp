//Given an array A[] of n numbers and another number x,
// determine whether or not there exist two elements in A
// whose sum is exactly x.


#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void compute(int arr[], int size, int sum)
{
    sort(arr,arr+size);
    bool output = false;
    int left = 0;
    int right = size-1;
    while(left < right)
    {
        if(arr[left]+arr[right] == sum)
        {
            output = true;
            break;
        }
        else if(arr[left]+arr[right]<sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    if(output==true) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main()
{
    int testcases;
    cin >> testcases;
    for(int i=0;i<testcases;i++)
    {
        int temp;
        cin >> temp;
        int sum;
        cin >> sum;
        int arr[temp];
        for(int j=0;j<temp;j++)
        {
            scanf("%d",&arr[j]);
        }
        compute(arr,temp,sum);
    }
    return 0;
}