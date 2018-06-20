# Score categories
# Change the values as you see fit
YACHT = 0
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11


def score(dice, category):
    if category == YACHT:
        return 50 if sum(dice) == 25 else 0
    elif category == FULL_HOUSE:
        if len(set(dice)) == 1:
            return 0
        dice.sort()
        midpoint = 3 if dice[1] == dice[2] else 2
        return sum(dice) if len(set(dice[:midpoint])) + len(set(dice[midpoint:])) == 2 else 0
    elif category == FOUR_OF_A_KIND:
        l = len([x for x in dice if x == dice[0]])
        if l == 1 and len(set(dice)) == 2:
            return dice[1] * 4 
        elif l == 4:
            return dice[0] * 4
        elif l == 5 and len(set(dice)) == 1:
            return dice[0] * 4
        else:
            return 0
    elif category == LITTLE_STRAIGHT:
        return 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0
    elif category == BIG_STRAIGHT:
        return 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0
    elif category == CHOICE:
        return sum(dice)
    return sum((x for x in dice if x == category))
