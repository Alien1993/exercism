def sum_of_multiples(limit, multiples):
    res = []
    for n in range(1, limit):
        for x in multiples:
            if n not in res and n % x == 0:
                res.append(n)
    return sum(res)
