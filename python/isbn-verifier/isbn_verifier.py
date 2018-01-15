import string


def verify(isbn):
    isbn = isbn.replace('-', '').upper()

    if len(isbn) != 10:
        return False

    count = 10
    total = 0
    for digit in isbn:
        # Returns if invalid characters are found
        if digit in string.ascii_uppercase and digit is not 'X':
            return False

        if digit is 'X':
            # X can all be on last position as a check
            if count != 1:
                return False
            digit = 10
        else:
            digit = int(digit)
        
        total += digit * count
        count -= 1

    return total % 11 == 0
