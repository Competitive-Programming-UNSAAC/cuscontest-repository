def quitar_vocales(s):
    return ''.join([x for x in s if x not in "aeiou"])

for _ in range(int(input())):
    a = [quitar_vocales(x) for x in input().split(' ')]
    a = [i for i in a if i != ""]
    print(' '.join(a))