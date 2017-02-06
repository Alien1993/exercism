def distance(strand1, strand2):
    if len(strand1) != len(strand2):
        raise ValueError

    strand1 = list(enumerate(strand1))
    strand2 = list(enumerate(strand2))
    distance = 0

    for i in strand1:
        if strand1[i[0]] != strand2[i[0]]:
            distance += 1
    return distance
