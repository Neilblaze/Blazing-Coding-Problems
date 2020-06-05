'''
Question Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
'''

t = int(input())
for k in range(t):
    x = list(map(int,input()))
    c = ''
    for i in x:
        c = c + '('*i + str(i) + ')'*i
    a = c
    c = a.replace(')(','')
    while(a!=c):
        a = c
        c = a.replace(')(','')
    print("Case #"+str(k+1)+":",c)
