"""This problem was asked by Salesforce.

The number 6174 is known as Kaprekar's contant, after the mathematician who discovered an 
associated property: for all four-digit numbers with at least two distinct digits, 
repeatedly applying a simple procedure eventually results in this value. 
The procedure is as follows:

For a given input x, create two new numbers that consist of the digits in x in 
ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:

4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Write a function that returns how many steps this will take for a given input N.
"""