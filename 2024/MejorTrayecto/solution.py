for _ in range(int(input())):
    graph = [[0 for _ in range(4)] for _ in range(4)]
    for _ in range(6):
        a, b, d = map(int, input().split())
        graph[a-1][b-1] = d
        graph[b-1][a-1] = d
    best = 0
    for a in range(4):
        for b in range(4):
            for c in range(4):
                if a == b or b == c or a == c:
                    continue
                d = 6-a-b-c
                best = max(best, graph[a][b]+graph[b][c]+graph[c][d])
    print(best)