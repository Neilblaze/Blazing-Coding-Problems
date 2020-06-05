'''
Question Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
'''
import math
t = int(input())
for z in range(t):
    n = int(input())
    k = 0
    r = 0
    c = 0
    Arr = []
    demo = []
    for i in range(n):
        demo.append(i+1)
    for i in range(n):
        A = list(map(int,input().split()))
        B = A.copy()
        B.sort()
        if B!=demo:
            r = r+1
        k = k + A[i]
        Arr.append(A)
    for i in range(n):
        C = []
        for j in range(n):
            C.append(Arr[j][i])
        C.sort()
        if C!=demo:
            c = c+1
    print('Case #'+str(z+1)+':',k,r,c)
