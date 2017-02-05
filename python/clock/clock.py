class Clock():
    """
    Class used to store, print and
    compare a timestamp formatted as HH:MM
    """

    def __init__(self, h, m):
        """Initialize time total number of minutes"""
        self.time = h % 24 * 3600 + m * 60
        self.time = int((self.time / 3600 % 24)) * 3600 \
            + int(self.time / 60 % 60) * 60

    def add(self, minutes):
        self.time += minutes * 60
        return self

    def __str__(self):
        hours = int(self.time / 3600 % 24)
        minutes = int(self.time / 60 % 60)
        return '{:02d}:{:02d}'.format(hours, minutes)

    # Comparisons
    def __lt__(self, other):
        return self.time < other.time

    def __le__(self, other):
        return self.time <= other.time

    def __eq__(self, other):
        return self.time == other.time

    def __ne__(self, other):
        return self.time != other.time

    def __gt__(self, other):
        return self.time > other.time

    def __ge__(self, other):
        return self.time >= other.time
