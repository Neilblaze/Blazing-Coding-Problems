// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

// Given a string, the task is to count all palindrome sub string in a given string. Length of palindrome sub string is greater than or equal to 2. 

// Examples: 

// Input : str = "abaab"
// Output: 3
// Explanation : 
// All palindrome substring are :
//  "aba" , "aa" , "baab" 

// Input : str = "abbaeae"
// Output: 4
// Explanation : 
// All palindrome substring are : 
// "bb" , "abba" ,"aea","eae"


// Discussion:

// The above problem can be recursively defined. 

// Initial Values : i = 0, j = n-1;
// Given string 'str'

// CountPS(i, j)
   
//    // If length of string is 2 then we 
//    // check both character are same or not 
//    If (j == i+1)
//       return str[i] == str[j]
//    //this condition shows that in recursion if i crosses j then it will be a invalid substring or
//    //if i==j that means only one character is remaining and we require substring of length 2 
//    //in both the conditions we need to return 0
//    Else if(i == j ||  i > j) return 0;
//    Else If str[i..j] is PALINDROME 
//       // increment count by 1 and check for 
//       // rest palindromic substring (i, j-1), (i+1, j)
//       // remove common palindrome substring (i+1, j-1)
//       return  countPS(i+1, j) + countPS(i, j-1) + 1 -
//                                    countPS(i+1, j-1);

//     Else // if NOT PALINDROME 
//        // We check for rest palindromic substrings (i, j-1)
//        // and (i+1, j)
//        // remove common palindrome substring (i+1 , j-1)
//        return  countPS(i+1, j) + countPS(i, j-1) - 
//                              countPS(i+1 , j-1);


// C++ program to find palindromic substrings of a string
#include <bits/stdc++.h>
using namespace std;

// Returns total number of palindrome substring of
// length greater then equal to 2
int CountPS(char str[], int n)
{
	// create empty 2-D matrix that counts all palindrome
	// substring. dp[i][j] stores counts of palindromic
	// substrings in st[i..j]
	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	// P[i][j] = true if substring str[i..j] is palindrome,
	// else false
	bool P[n][n];
	memset(P, false, sizeof(P));

	// palindrome of single length
	for (int i = 0; i < n; i++)
		P[i][i] = true;

	// palindrome of length 2
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1]) {
			P[i][i + 1] = true;
			dp[i][i + 1] = 1;
		}
	}

	// Palindromes of length more than 2. This loop is
	// similar to Matrix Chain Multiplication. We start with
	// a gap of length 2 and fill the DP table in a way that
	// gap between starting and ending indexes increases one
	// by one by outer loop.
	for (int gap = 2; gap < n; gap++) {
		// Pick starting point for current gap
		for (int i = 0; i < n - gap; i++) {
			// Set ending point
			int j = gap + i;

			// If current string is palindrome
			if (str[i] == str[j] && P[i + 1][j - 1])
				P[i][j] = true;

			// Add current palindrome substring ( + 1)
			// and rest palindrome substring (dp[i][j-1] +
			// dp[i+1][j]) remove common palindrome
			// substrings (- dp[i+1][j-1])
			if (P[i][j] == true)
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1
						- dp[i + 1][j - 1];
			else
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j]
						- dp[i + 1][j - 1];
		}
	}

	// return total palindromic substrings
	return dp[0][n - 1];
}

// Driver code
int main()
{
	char str[] = "abaab";
	int n = strlen(str);
	cout << CountPS(str, n) << endl;
	return 0;
}

// Output: 3

// Time complexity: O(n2) 
// Auxiliary Space: O(n2) 