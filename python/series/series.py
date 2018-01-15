def slices(series, length):
    if length == 0 or length > len(series):
        raise ValueError('Length of slice must be between 0 and length of series')
    result = []
    for index, value in enumerate(series):
        if index > len(series) - length:
            break
        result.append([int(x) for x in series[index:index + length]])
    return result
