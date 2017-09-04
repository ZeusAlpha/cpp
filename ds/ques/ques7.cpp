#include <bits/stdc++.h>
using namespace std;

int binary_search1(int arr[], int start, int end, int key)
{
    if(start<=end)
    {
        int mid = start + (end-start)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        else if(key<arr[mid])
        {
           return binary_search1(arr,start,mid-1,key);
        }
        else
        {
           return binary_search1(arr,mid+1,end,key);
        }
    }
    return -1;
}

int findRotationPoint(int arr[], int start, int end, int key)
{
        if(start<end)
        {
            if(arr[start]<arr[end])
            {
                return binary_search1(arr,start,end,key);
            }
            else
            {
                int mid = start + (end-start)/2;
                return findRotationPoint(arr,start,mid,key);
                return findRotationPoint(arr,mid+1,end,key);
            }
        }
}

int main()
{
    int testcases;
    cin >> testcases;

    for(int i=0;i<testcases; i++)
    {
        int size;
        cin >> size;
        int arr[size];
        for(int j=0;j<size;j++)
        {
            int k;
            cin >> k;
            arr[j] = k;
        }
        int key;
        cin >> key;
        int alpha = findRotationPoint(arr,0,size-1,key);
        cout << alpha << "   sfdsd   " << endl;
    }
    return 0;
}