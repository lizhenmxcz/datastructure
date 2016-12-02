/************************************************************
Copyright (C)
FileName: bigSequence.c
Author: leezy
Version : 1.0
Date: 2016/11/30 22:25
Description: max subsequence sum
***********************************************************/
#include <stdio.h>
#include <time.h>
/**
@param data length
@function run time O(N*N*N)
**/
int maxSubsequenceSumN3(int *data, int length)
{
	int maxSum = 0, currentSum = 0, i,j,k;
	for(i = 0; i < length; i++)
	{
		for(j = i; j < length; j++)
		{
			currentSum = 0;
			for(k = i; k <= j; k++)
			{
				currentSum += data[k];
			}
			if(maxSum < currentSum)
			{
				maxSum = currentSum;

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
	int maxSum = 0, currentSum = 0, i, k;
	for(i = 0; i < length; i++)
	{
		currentSum = 0;
		for(k = i; k < length; k++)
		{
			currentSum += data[k];
		}
		if(maxSum < currentSum)
		{
			maxSum = currentSum;

		}
	}
	return maxSum;
}
/**
@param data length
@function run time O(N*logN)
**/
int maxSubsequenceSumNLOGN(int *data, int start, int end)
{
	int maxLeft = 0; // the max sum in the left sub
	int maxLeftWithBorder = 0; //the max sum in the left with the last number
	int maxRight = 0;// the max sum in the right sub
	int maxRightWithBorder = 0;//the max sum in the right with the first number
	int maxMid = 0; //the max sum in the middle
	int mid = (end + start) / 2;
	int maxSum = 0;
	if (start == end)
	{
		if (data[start] > 0)
		{
			return data[start];
		}
		else return 0;
	}
	maxLeft = maxSubsequenceSumNLOGN(data, start, mid);
	printf("left %d  ", maxLeft);
	maxRight = maxSubsequenceSumNLOGN(data, mid+1, end);
	printf("right %d  ", maxRight);
	int i, j, leftCurSum = 0, rightCurSum = 0;
	for (i = mid; i >= start; i--)
	{
		leftCurSum += data[i];
		if(maxLeftWithBorder < leftCurSum)
			maxLeftWithBorder = leftCurSum;
	}
	for (j = mid+1; j <= end; j++)
	{
		rightCurSum += data[j];
		if(maxRightWithBorder < rightCurSum)
			maxRightWithBorder = rightCurSum;
	}
	maxMid = maxLeftWithBorder + maxRightWithBorder;
	printf("mid %d\n", maxMid);
	if (maxLeft > maxRight)
	{
		maxSum = maxLeft;
	}
	else maxSum = maxRight;
	if (maxSum < maxMid)
	{
		maxSum = maxMid;
	}
	return maxSum;
}
/**
@param data length
@function run time O(N)
**/
int maxSubsequenceSumN(int *data, int length)
{
	int currentSum = 0, maxSum = 0, i;
	for (i = 0; i < length; ++i)
	{
		currentSum += data[i];
		if (currentSum < 0)
		{
			currentSum = 0;
		}
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
	}
	return maxSum;
}
int main(int argc, char const *argv[])
{
	double start, finish;
	double duration;
	int data[31] = {4,7,-6,2,-7,9,5,5,-7,3,7,-9,-5,8,26,3,23,4,-56,-5,-2,-90,-7,4,6,8,-4,9,8,63,3};
	//int data[7] = {1, -3, 4, -2, -1, 5, -2};
	start = clock();
	//int sum = maxSubsequenceSumNLOGN(data, 0, 24);
	//int sum = maxSubsequenceSumN2(data, 25);
	//int sum = maxSubsequenceSumN3(data, 25);
	int sum = maxSubsequenceSumN(data, 31);
	finish = clock();
	duration = (double)(finish - start);
	printf("the sum is %d, and cost time is %f\n",sum, duration);
	return 0;
}