# Algorithm

We have an array of sequence numbers of the songs. We will perform a random shuffling of the array and play the songs in that order. For doing it:

Random Shuffling of the array, from index i to index j:

RandomShuffle(i,j)

        if i == j:        return;

        Choose a random element, x from i to j

        Swap a[x] and a[i]

        RandomShuffle(i+1,j)

The above algorithm takes O(n) time with O(1) space.

The points to note are: 

     The above algorithm guarantees every possible shuffle with equal probability

                 Probability of i being the first element is 1/n

                 Probability of i being the second element is (1-1/n) (1/n-1) = 1/n

                 Probability of i being the third one is (1-1/n)(1-1/n-1)(1/n-2) = 1/n

                 ......

So, after the random shuffling of 0 to n-1, we will play the songs of the array in the order. Once all songs are played we will repeat the above step again.