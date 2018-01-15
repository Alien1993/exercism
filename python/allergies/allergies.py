class Allergies(object):

    def __init__(self, score):
        # Clamps allergies scores 
        if score > 256:
            score -= 256
        self.allergens = []
        items = {
            1: 'eggs',
            2: 'peanuts',
            4: 'shellfish',
            8: 'strawberries',
            16: 'tomatoes',
            32: 'chocolate',
            64: 'pollen',
            128: 'cats'
        }
        for item in sorted(items.keys(), reverse=True):
            if (score / item >= 1):
                self.allergens.append(items[item])
                score -= item


    def is_allergic_to(self, item):
        return item in self.allergens

    @property
    def lst(self):
        return self.allergens
