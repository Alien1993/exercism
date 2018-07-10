from string import ascii_lowercase, punctuation
from textwrap

TRANSLATION_TABLE = str.maketrans(ascii_lowercase, ascii_lowercase[::-1])

def encode(plain_text):
    translated = plain_text.lower().translate(TRANSLATION_TABLE)
    translated = translated.replace(' ', '')
    for p in punctuation:
        translated = translated.replace(p, '')
    return ' '.join(textwrap.wrap(translated, 5))

def decode(ciphered_text):
    return ciphered_text.lower().replace(' ', '').translate(TRANSLATION_TABLE)
