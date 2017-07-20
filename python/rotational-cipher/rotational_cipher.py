import string


def rotate(sentence, shift):
    # Creates shifted cipher
    cipher = string.ascii_lowercase[shift:] + string.ascii_lowercase[:shift] +\
        string.ascii_uppercase[shift:] + string.ascii_uppercase[:shift]
    # Creates translator to shift sentence
    translator = str.maketrans(string.ascii_letters, cipher)
    # Returns shifted sentence
    return sentence.translate(translator)
