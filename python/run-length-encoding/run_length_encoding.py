def decode(data):
    # Result to return
    result = ""

    # Stores count of letters to append
    count = ""

    # Iterates data to decode it
    for l in data:
        if l.isdigit():
            # If current char is a digit append it to count of letter
            count += l
        else:
            # Appends number of letters specified by count
            for i in range(0, int(count or 1)):
                result += l
            # Resets count
            count = ""

    # Returns decoded result
    return result


def encode(data):
    # Handles empty data right off the bat
    if data == "":
        return ""

    # Result to return
    encoded = ""

    # Starting previous value is the first element
    previous = data[0]

    # Stores the count of current letter
    count = 0

    # Iterates the data to encode it
    for l in data:
        if l == previous:
            # Increases count if previous char is equals to current one
            count += 1
        else:
            # If previous char is different from current one appends previous one
            # and its count if greater than 1
            if count > 1:
                encoded += str(count)
            encoded += previous
            count = 1
        # Sets previous char to current one at end of loop
        previous = l

    # Handles last chars since they're not handled in loop
    if count > 1:
        encoded += str(count)
    encoded += previous

    # Returns the encoded result
    return encoded
