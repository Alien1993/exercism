

class BowlingGame(object):
    def __init__(self):
        self.frames = []

    def roll(self, pins):
        if pins < 0 or pins > 10:
            raise ValueError

        if len(self.frames) == 0:
            self.frames.append([pins])
        elif len(self.frames) == 10:
            if len(self.frames[-1]) == 2 and sum(self.frames[-1]) < 10:
                raise IndexError
            elif len(self.frames[-1]) == 2 and 10 < sum(self.frames[-1]) < 20 and pins == 10:
                raise ValueError
            else:
                self.frames[-1].append(pins)
        else:
            if len(self.frames[-1]) < 2:
                if sum(self.frames[-1]) == 10:
                    self.frames.append([pins])
                elif sum(self.frames[-1], pins) > 10:
                    raise ValueError
                else:
                    self.frames[-1].append(pins)
            else:
                self.frames.append([pins])

    def score(self):
        if len(self.frames) < 10:
            raise IndexError
        
        if sum(self.frames[-1]) >= 10 and len(self.frames[-1]) < 3:
            raise IndexError 

        points = 0
        i = 0

        for i, f in enumerate(self.frames[:-1]):
            next_frame = self.frames[i + 1]

            # A frame with only a roll must be a strike
            if len(f) == 1:
                if len(next_frame) == 2:
                    points += 10 + sum(next_frame)
                elif len(next_frame) == 3:
                    points += 10 + next_frame[0] + next_frame[1]
                else:
                    points += 10 + next_frame[0] + self.frames[i + 2][0]
                continue
            elif f[0] + f[1] == 10:
                points += 10 + next_frame[0]
            else:
                points += f[0] + f[1]

        # Last frame
        points += sum(self.frames[-1])

        return points

