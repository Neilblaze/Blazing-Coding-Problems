"""This problem was asked by MIT.

Blackjack is a two player card game whose rules are as follows:

The player and then the dealer are each given two cards.
The player can then "hit", or ask for arbitrarily many additional cards, so long as their total does not exceed 21.
The dealer must then hit if their total is 16 or lower, otherwise pass.
Finally, the two compare totals, and the one with the greatest sum not exceeding 21 is the winner.
For this problem, cards values are counted as follows: each card between 2 and 10 counts as their face value, 
face cards count as 10, and aces count as 1.

Given perfect knowledge of the sequence of cards in the deck, implement a blackjack s
olver that maximizes the player's score (that is, wins minus losses).
"""