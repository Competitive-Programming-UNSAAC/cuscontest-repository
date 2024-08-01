YES = "S"
NO = "N"

for _ in range(int(input())):
    n = int(input())
    eventos = list(map(int, input().split()))

    acumulado = [100 / eventos[i] if eventos[i] > 100 else 1 for i in range(n)]
    for i in range(n):
        if i !=0:
            acumulado[i] = acumulado[i] * acumulado[i - 1]
    acumulado = [1] + acumulado

    for _ in range(int(input())):
        x, y, p = map(int, input().split())
        print(YES if 100 * (acumulado[x] / acumulado[y]) >= p else NO)