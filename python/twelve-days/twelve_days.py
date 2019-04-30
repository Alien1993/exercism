DAYS = ['first', 'second', 'third', 'fourth', 'fifth', 'sixth', 'seventh', 'eighth', 'ninth', 'tenth', 'eleventh', 'twelfth']
GIFTS = [
    'twelve Drummers Drumming,',
    'eleven Pipers Piping,',
    'ten Lords-a-Leaping,',
    'nine Ladies Dancing,',
    'eight Maids-a-Milking,',
    'seven Swans-a-Swimming,',
    'six Geese-a-Laying,',
    'five Gold Rings,',
    'four Calling Birds,',
    'three French Hens,',
    'two Turtle Doves, and',
    'a Partridge in a Pear Tree.'
]

def recite(start_verse, end_verse):
    res = []
    for i in range(start_verse - 1, end_verse):
        verse = f'On the {DAYS[i]} day of Christmas my true love gave to me: '
        verse += ' '.join(GIFTS[-i-1:])
        res.append(verse)
    return res

