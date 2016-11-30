/************************************************************
Copyright (C)
FileName: bigSequence.c
Author: leezy
Version : 1.0
Date: 2016/11/30 22:25
Description: max subsequence sum
***********************************************************/
#include <stdio.h>
/**
@param data length
@function run time O(N*N*N)
**/
int maxSubsequenceSumN3(int *data, int length)
{
	int maxSum=0, currentSum=0, i,j,k;
	for(i=0;i<length;i++)
	{
		for(j=i;j<length;j++)
		{
			currentSum=0;
			for(k=i;k<=j;k++)
			{
				currentSum+=data[k];
			}
			if(maxSum<currentSum)
			{
				maxSum=currentSum;

			}
         
		}
	}
	return maxSum;
}
/**
@param data length
@function run time O(N*N)
**/
int maxSubsequenceSumN2(int *data, int length)
{
	int maxSum=0, currentSum=0, i,k;
	for(i=0;i<length;i++)
	{
		currentSum=0;
		for(k=i;k<length;k++)
		{
			currentSum+=data[k];
		}
		if(maxSum<currentSum)
		{
			maxSum=currentSum;

		}
	}
	return maxSum;
}
int main(int argc, char const *argv[])
{
	int data[25]={4,7,-6,2,-7,9,5,5,-7,3,7,-9,-5,8,26,3,23,4,6,8,-4,9,8,63,3};
	printf("%d\n",maxSubsequenceSumN3(data,25));
	return 0;
}