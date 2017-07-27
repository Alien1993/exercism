# Calculates square of sum of first n numbers
def square_of_sum(n):
    return sum((i for i in range(1, n + 1)))**2


# Calculates sum of square of first n numbers
def sum_of_squares(n):
    return sum((i**2 for i in range(1, n + 1)))


# Returns difference between square of sum and sum of squares
def difference(n):
    return abs(square_of_sum(n) - sum_of_squares(n))
