for _ in range(int(input())):
    ai = bi = int(2e9)
    aj = bj = -ai
    for _ in range(int(input())):
        x, y = [int(x) for x in input().split(' ')]
        ai = min(ai, x + y)
        aj = max(aj, x + y)
        bi = min(bi, x - y)
        bj = max(bj, x - y)
    print(max(aj - ai, bj - bi))
