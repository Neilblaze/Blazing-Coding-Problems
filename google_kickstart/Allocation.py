"""
Question Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
"""

t = int(input())
for ind in range(t):
    n, b = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort()
    smm = 0
    ans = 0
    for i in range(n):
        smm = smm + A[i]
        if smm>b:
            break
        else:
            ans = ans+1
    print("Case #"+str(ind+1)+": "+str(ans))
