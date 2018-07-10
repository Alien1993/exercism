from math import sqrt

def sieve(limit):
    sieved = [v > 1 for v in range(0, limit + 1)]
    for i in range(2, limit + 1):
        if sieved[i]:
            for j in (pow(i, 2) + i * x for x in range(0, limit + 1)):
                if j > limit:
                    break
                sieved[j] = False
    return [i for i, v in enumerate(sieved) if v]


