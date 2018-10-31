def abbreviate(words):
    acronym = ''
    previous_char = ''
    for c in words:
        if not previous_char.isalpha() and c.isalpha():
            acronym += c.upper()
        previous_char = c
    return acronym
