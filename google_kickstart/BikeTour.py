"""
Question Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
"""

t = int(input())
for im in range(t):
    n = int(input())
    x = 0
    A = list(map(int,input().split()))
    for i in range(1,n-1):
        if A[i]>A[i-1] and A[i]>A[i+1]:
            x = x+1;
    print("Case #"+str(im+1)+": "+str(x))
