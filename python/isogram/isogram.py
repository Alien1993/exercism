import string

def is_isogram(sentence):
    # Converts sentence to lowercase and strips all spaces
    sentence = sentence.lower().strip()
    # Creates a set to keep track of found letters
    letters = set()
    # Loops every letters in sentence
    for l in sentence:
        # Checks if current char is a letter of the alphabet, if not skips to
        # next one, this is done to avoid punctuation characters
        if l not in string.ascii_lowercase: continue

        # If letter is already been found in sentence return False since we there
        # can't be two equal letters in an isogram, else adds it our set of found
        # letters
        if l in letters:
            return False
        else:
            letters.add(l)
    # If the whole sentence has been parsed and not two equal letters have been
    # found return True, since in that case we have found or isogram
    return True
