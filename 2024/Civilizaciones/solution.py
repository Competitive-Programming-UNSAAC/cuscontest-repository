with open("./in/1.in",'r') as inp:

    t = int(inp.readline())
    for _ in range(t):
        n = int(inp.readline())
        arreglo_de_eventos = list(map(int, inp.readline().split()))
        arreglo_de_multiplicaciones_acumuladas = [100/arreglo_de_eventos[i] if arreglo_de_eventos[i]>100 else 1 for i in range(n)]
        for i in range(n):
            if i !=0: arreglo_de_multiplicaciones_acumuladas[i] = arreglo_de_multiplicaciones_acumuladas[i]*arreglo_de_multiplicaciones_acumuladas[i-1]
        arreglo_de_multiplicaciones_acumuladas = [1] + arreglo_de_multiplicaciones_acumuladas   
        q = int(inp.readline())
        for qi in range(q):
            x,y,p = map(int, inp.readline().split())
            print("S" if 100*(arreglo_de_multiplicaciones_acumuladas[x]/arreglo_de_multiplicaciones_acumuladas[y]) >= p else "N")