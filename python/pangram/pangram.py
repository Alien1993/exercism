from string import ascii_lowercase

def is_pangram(sentence):
    letters = set()
    for i in sentence:
        if (i.lower() in ascii_lowercase):
            letters.add(i.lower())
    return len(letters) == len(ascii_lowercase)
