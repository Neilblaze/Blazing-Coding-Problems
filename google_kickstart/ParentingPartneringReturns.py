'''
Question Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
'''
t = int(input())
for xyz in range(t):
    X = []
    M = [0]*1441
    N = M.copy()
    X.append(M)
    X.append(N)
    ss = ''
    A = []
    n = int(input())
    for i in range(n):
        a, b = map(int,input().split())
        B = []
        B.append(a)
        B.append(b)
        B.append(i)
        A.append(B)
    A.sort()
    for i in range(n): 
        if X[0][A[i][0]]==0:
            ss = ss + 'C'
            for j in range(A[i][0],A[i][1]):
                X[0][j] = X[0][j] + 1
        elif (X[0][A[i][0]]==1 and X[1][A[i][0]]==0):
            ss = ss + 'J'
            for j in range(A[i][0],A[i][1]):
                X[1][j] = X[1][j] + 1
        else:
            ss = 'IMPOSSIBLE'
            break
    if ss!='IMPOSSIBLE':
        SS = list(ss)
        RES = []
        for i in range(n):
            REQ = []
            REQ.append(A[i][2])
            REQ.append(SS[i])
            RES.append(REQ)
        RES.sort()
        res = ''
        for i in range(n):
            res = res + str(RES[i][1])
    else:
        res = ss
    print('Case #'+str(xyz+1)+':',res)
