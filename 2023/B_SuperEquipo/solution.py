import copy
def actualizar(tabla):
    for i in range(N):
        for j in range(N):
            if l[i][j] == 0:
                if (l[i-1][j] + l[i][j-1] + l[(i+1)%N][j] + l[i][(j+1)%N]) in vivoMuert:
                    tabla[i][j] = 1
                else:
                    tabla[i][j] = 0
            else:
                if (l[i-1][j] + l[i][j-1] + l[(i+1)%N][j] + l[i][(j+1)%N]) in vivoReg:
                    tabla[i][j] = 1
                else:
                    tabla[i][j] = 0
    return tabla

for _ in range(int(input())):
    regla_muerto = input()
    regla_vivo = input()
    vivoReg = [-1]*5
    vivoMuert = [-1]*5
    for i in range(5):
        vivoReg[i] = i if regla_vivo[i] == '*' else -1
        vivoMuert[i] = i if regla_muerto[i] == '*' else -1
    N,M = list(map(int,input().split()))
    l = [[0] for i in range(N)]
    for i in range(N):
        l[i] = list(map(int,list([('1' if x == '*' else '0') for x in input()])))
    for _ in range(M):
        l = actualizar(copy.deepcopy(l))
    for i in range(N):
        print (''.join(map(str, [('*' if x == 1 else '.') for x in l[i]])))