for _ in range(int(input())):
    puntos = []
    respuesta = 0
    for _ in range(int(input())):
        xi, yi = [int(x) for x in input().split(' ')]
        distancia = max([ abs(xi - xj) + abs(yi - yj) for xj, yj in puntos] + [0])
        respuesta = max(respuesta, distancia)
        puntos += [[xi, yi]]
    print(respuesta)
