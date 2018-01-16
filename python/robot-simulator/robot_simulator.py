# Globals for the bearings
# Change the values as you see fit
EAST = (1, 0)
NORTH = (0, 1)
WEST = (-1, 0)
SOUTH = (0, -1)


class Robot(object):
    def __init__(self, bearing=NORTH, x=0, y=0):
        self.bearing = bearing
        self.coordinates = (x, y)

    def advance(self):
        x = self.coordinates[0] + self.bearing[0]
        y = self.coordinates[1] + self.bearing[1]
        self.coordinates = (x, y)

    def turn_left(self):
        x = self.bearing[0] * 0 + self.bearing[1] * -1
        y = self.bearing[0] * 1 + self.bearing[1] * 0
        self.bearing = (x, y)

    def turn_right(self):
        x = self.bearing[0] * 0 + self.bearing[1] * 1
        y = self.bearing[0] * -1 + self.bearing[1] * 0
        self.bearing = (x, y)

    def simulate(self, orders):
        for order in orders:
            if order == "A":
                self.advance()
            elif order == "L":
                self.turn_left()
            elif order == "R":
                self.turn_right()