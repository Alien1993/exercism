def hey(sentence):
    # Strips unnecessary whitespace
    sentence = sentence.strip()
    # Answers to nothing
    if len(sentence) == 0:
        return 'Fine. Be that way!'
    # Answers to yells
    if sentence.isupper():
        return 'Whoa, chill out!'
    # Answers to questions
    if sentence[-1] == '?':
        return 'Sure.'
    # Answers to everything else
    return 'Whatever.'
