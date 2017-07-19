from calendar import Calendar
import datetime

class MeetupDayException(Exception):
    pass

def meetup_day(year, month, day, ordinal):
    # Gets day of week number
    day = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"].index(day)
    # Converts the ordinal to a number
    ordinal = ["teenth", "1st", "2nd", "3rd", "4th", "5th", "last"].index(ordinal)
    # Used to count number of day found
    count = 0
    # Calendar used to get a list of days for specified month
    c = Calendar()

    # If we're searching for the last day of the month we search backwards
    if ordinal == 6:
        for d in list(c.itermonthdays2(year, month))[::-1]:
            # Skips days belonging to other months
            if d[0] == 0:
                continue
            # Returns date as soon as we find the day
            if d[1] == day:
                return datetime.date(year, month, d[0])

    # Iterates days of specified months
    for d in c.itermonthdays2(year, month):
        # Skips days belonging to other months
        if d[0] == 0:
            continue

        # Checks if current day is a teenth day if we're searching for one
        if ordinal == 0:
            if d[0] in range(13, 20):
                if d[1] == day:
                    return datetime.date(year, month, d[0])

        # Increments count if day of the week we're searching is found
        if d[1] == day:
            count += 1

        # Returns date if specified day is found
        if count == ordinal and count != 0:
            return datetime.date(year, month, d[0])

    # Raises exception if no day is found
    raise MeetupDayException()
