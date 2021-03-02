"""
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

A network consists of nodes labeled 0 to N. You are given a list of edges (a, b, t), 
describing the time t it takes for a message to be sent from node a to node b. 
Whenever a node receives a message, it immediately passes the message on to a 
neighboring node, if possible.

Assuming all nodes are connected, determine how long it will take for every node 
to receive a message that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating the message 
from 0 -> 2 -> 3 -> 4 will take that much time."""