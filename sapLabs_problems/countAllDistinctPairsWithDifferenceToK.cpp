// https://www.geeksforgeeks.org/count-pairs-difference-equal-k/

// Given an integer array and a positive integer k, count all distinct pairs with differences equal to k. 

// Examples: 

// Input: arr[] = {1, 5, 3, 4, 2}, k = 3
// Output: 2
// There are 2 pairs with difference 3, the pairs are {1, 4} and {5, 2} 

// Input: arr[] = {8, 12, 16, 4, 0, 20}, k = 4
// Output: 5
// There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, 
// {8, 12}, {12, 16} and {16, 20} 

// Normal Solution : O(n^2)

/* A simple program to count pairs with difference k*/
#include<iostream>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0;
	
	// Pick all elements one by one
	for (int i = 0; i < n; i++)
	{	
		// See if there is a pair of this picked element
		for (int j = i+1; j < n; j++)
			if (arr[i] - arr[j] == k || arr[j] - arr[i] == k )
				count++;
	}
	return count;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 5, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}

// 
// 
// 
// 


// Optimized solution (Using Sorting):

// We can find the count in O(nLogn) time using a O(nLogn) sorting algorithm like Merge Sort, Heap Sort, etc. Following are the detailed steps. 

// 1) Initialize count as 0
// 2) Sort all numbers in increasing order.
// 3) Remove duplicates from array.
// 4) Do following for each element arr[i]
//    a) Binary Search for arr[i] + k in subarray from i+1 to n-1.
//    b) If arr[i] + k found, increment count. 
// 5) Return count. 


/* A sorting based program to count pairs with difference k*/
#include <iostream>
#include <algorithm>
using namespace std;

/* Standard binary search function */
int binarySearch(int arr[], int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low)/2;
		if (x == arr[mid])
			return mid;
		if (x > arr[mid])
			return binarySearch(arr, (mid + 1), high, x);
		else
			return binarySearch(arr, low, (mid -1), x);
	}
	return -1;
}

/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0, i;
	sort(arr, arr+n); // Sort array elements

	/* code to remove duplicates from arr[] */

	// Pick a first element point
	for (i = 0; i < n-1; i++)
		if (binarySearch(arr, i+1, n-1, arr[i] + k) != -1)
			count++;

	return count;
}

// Driver program
int main()
{
	int arr[] = {1, 5, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}

// Output: Count of pairs with given diff is 2

// Time complexity: The first step (sorting) takes O(nLogn) time. 
// The second step runs binary search n times, so the time complexity of second step is also O(nLogn). 
// Therefore, overall time complexity is O(nLogn).