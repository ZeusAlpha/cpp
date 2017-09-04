/*Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example:
 if you had four matrices A, B, C, and D, you would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
     (AB)C = (10×30×5) + (10×5×60) 
           = 1500 + 3000 
           = 4500 operations
     A(BC) = (30×5×60) + (10×30×60) 
           = 9000 + 18000 
           = 27000 operations.
Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.

  Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 
  20x30, 30x10 and 10x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained 
  by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: 30000 
  There are 4 matrices of dimensions 10x20, 
  20x30, 30x40 and 40x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained by 
  putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30*/
  
  //PROBLEM OF DP
  #include<bits/stdc++.h>
  #include<limits.h>
  using namespace std;
  
  int matrixChainMultiplication(int arr[], int size)
  {
  	int a[size][size];
  	
  	for(int i=0;i<size;i++)
  	{
  		a[i][i] = 0;
  	}
  	for(int length=2;length<size;length++)
  	{
  		for(int start=1;start<size-start+1;start++)
  		{
  			int end = start + length - 1;
  			a[start][end] = INT_MAX;
  			for(int k=start; k< end-1; k++)
  			{
  				int temp = a[start][k] + a[k+1][end] + arr[start-1]*arr[k]*arr[end];
  				if(temp < a[start][end])
  				{
  					a[start][end] = temp;
  				}
  			}
  		}
  	}
  	return a[1][size-1];
  }
  
  
  int main()
  {
  	int testcases;
  	cin >> testcases;
  	for(int i=0;i<testcases;i++)
  	{
  		int size;
  		cin >> size;
  		int arr[size];
  		for(int j=0;j<size;j++)
  		{
  			int temp;
  			cin >> temp;
  			arr[j]=temp;
  		}
  		int output = matrixChainMultiplication(arr,size);
  		cout << output << endl;
  	}	
  	
  	
  	return 0;
  }
