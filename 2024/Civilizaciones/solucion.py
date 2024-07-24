t = int(input())
for _ in range(t):
    n = int(input())
    arreglo_de_eventos = list(map(int, input().split()))
    arreglo_de_multiplicaciones_acumuladas = [100/arreglo_de_eventos[i] if arreglo_de_eventos[i]>100 else 1 for i in range(n)]
    for i in range(n):
        if i !=0: arreglo_de_multiplicaciones_acumuladas[i] = arreglo_de_multiplicaciones_acumuladas[i]*arreglo_de_multiplicaciones_acumuladas[i-1]
    arreglo_de_multiplicaciones_acumuladas = [1] + arreglo_de_multiplicaciones_acumuladas   
    print(arreglo_de_multiplicaciones_acumuladas)
    q = int(input())
    for qi in range(q):
        x,y,p = map(int, input().split())
        print("S" if 100*(arreglo_de_multiplicaciones_acumuladas[x]/arreglo_de_multiplicaciones_acumuladas[y]) >= p else "N")