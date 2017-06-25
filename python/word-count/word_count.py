# -*- coding: utf-8 -*-

import string

def word_count(sentence):
    result = {}
    translator = str.maketrans(string.punctuation, " " * len(string.punctuation))
    sentence = sentence.lower().translate(translator).split()
    for word in sentence:
        result[word] = result.get(word, 0) + 1
    return result
