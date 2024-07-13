from random import randint
import numpy as np


def generate_fence(length):
    numbers = np.random.binomial(n=1, p=np.random.rand(), size=length)
    return ''.join(map(str, numbers))

N = 300
M = 1000

print(N)
for ith_case in range(N):
    print(generate_fence(randint(1, M + 1)))
