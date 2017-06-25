# -*- coding: utf-8 -*-

import re

def word_count(sentence):
    result = {}
    sentence = re.findall('[^\W_]+', sentence.lower())
    for word in sentence:
        result[word] = result.get(word, 0) + 1
    return result
