def move_all_to(p, fence, ones):
    i = (i for i, x in enumerate(fence) if x == 1)
    s = 0
    for p in range(p, p + ones):
        s += abs(next(i) - p)
    return s

def solve(fence):
    ones = sum(fence)
    length = len(fence) - ones
    if length == 0:
        return 0
    return min(move_all_to(p, fence, ones) for p in range(length))

N = int(input())

for ith_case in range(1, 1 + N):
    fence = [int(x) for x in input()]
    print('Caso #{case}: {answer}'.format(case=ith_case, answer=solve(fence)))
