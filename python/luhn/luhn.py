class Luhn(object):
    def __init__(self, card_num):
        self.number = ''.join([n for n in card_num.replace(' ', '')])

    def double(self, digit):
        digit *= 2
        if digit > 9:
            digit -= 9
        return digit

    def is_valid(self):
        if len(self.number) < 2:
            return False

        converted = []
        for i, n in enumerate(self.number[::-1]):
            if not n.isdigit():
                return False

            n = int(n)
            if i % 2:
                n = self.double(n)
            converted.append(n)

        return sum(converted) % 10 == 0
