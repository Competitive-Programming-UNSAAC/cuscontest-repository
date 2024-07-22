t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    B = [100/A[i] if A[i]>100 else 1 for i in range(n)]
    for i in range(n):
        if i !=0: B[i] = B[i]*B[i-1]
    B = [1] + B   
    print(B)
    q = int(input())
    for qi in range(q):
        x,y,p = map(int, input().split())
        print("S" if 100*(B[x]/B[y]) < p else "N")