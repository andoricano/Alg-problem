import sys
sys.setrecursionlimit(10**5)

def hanoi(n, here, to,sub):
    if n == 1:
        print(here, to)
        return
    hanoi(n-1, here, sub,to)# 위에 원반 치우기
    print(here, to)
    hanoi(n-1, sub, to, here)# 치워둔 거 가져오기

n = int(input())
print(2**n-1)
hanoi(n,1,3,2)