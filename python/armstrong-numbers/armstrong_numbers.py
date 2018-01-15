import math


def is_armstrong(number):
    number = str(number)
    number_of_digits = len(number)
    result = 0
    for i in number:
        result += math.pow(int(i), number_of_digits)
    return result == int(number)


