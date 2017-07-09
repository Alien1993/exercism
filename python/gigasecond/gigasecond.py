import datetime

def add_gigasecond(date):
    # Creates a delta of a gigasecond
    gigasecond = datetime.timedelta(seconds=1_000_000_000)
    # Returns the original date plus the gigasecond delta
    return date + gigasecond
