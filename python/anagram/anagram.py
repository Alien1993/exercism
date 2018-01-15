def detect_anagrams(word, candidates):
    word = word.lower()
    anagrams = []
    for candidate in candidates:
        # Two words can't be anagrams if they have different length or if they
        # are identical
        if len(candidate) is not len(word) or candidate.lower() == word:
            continue

        c = list(candidate.lower())
        for l in word:
            if l in c:
                c.pop(c.index(l))

        if len(c) == 0:
            anagrams.append(candidate)

    return anagrams

