for _ in range(int(input())):
    n = int(input())
    valores = [int(x) for x in input().split(' ')]
    costos = [int(x) for x in input().split(' ')]
    ganancias = [max(valores[i] - costos[i], 0)  for i in range(n)]
    print(sum(ganancias))
