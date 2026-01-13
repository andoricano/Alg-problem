import sys
sys.setrecursionlimit(10**5)

ans = [0,0,0]
m1 = zero = p1 = 0

def searching(canvas, r,c,n):
    for a in range(-1,2):
        t = False
        for i in range(r, r+n):
            for j in range(c, c+ n):
                if a != canvas[i][j] :
                    t = True
                    break
            
            if t :
                break
        if not t :
            ans[a+1] += 1
            for i in range(r, r+n):
                for j in range(c, c + n):
                    canvas[i][j] = 3 # 3==checked
            break

def recursion(canvas, r,c, n):
    if n < 1 : return
    
    searching(canvas, r,c,n)
    
    for i in range(3):
        for j in range(3):
            recursion(canvas, r + (n//3) * i , c + (n//3) * j, n//3)


n = int(input())

canvas = [[0] * n for i in range(n)]
for i in range(n) :
    canvas[i] = list(map(int,input().split(" ")))

recursion(canvas, 0, 0, n)

for i in ans:
    print(i)