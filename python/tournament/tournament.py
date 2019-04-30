from operator import attrgetter
from dataclasses import dataclass

@dataclass
class Team:
    name: str
    played: int = 0
    won: int = 0
    draw: int = 0
    loss: int = 0
    points: int = 0

    def wins(self):
        self.played += 1
        self.won += 1
        self.points += 3

    def draws(self):
        self.played += 1
        self.draw += 1
        self.points += 1

    def loses(self):
        self.played += 1
        self.loss += 1


def tally(tournament_results):
    teams = {}

    for row in tournament_results.splitlines():
        first, second, result = row.split(';')

        team_one = teams.get(first, Team(first))
        team_two = teams.get(second, Team(second))

        if result == 'win':
            team_one.wins()
            team_two.loses()
        elif result == 'loss':
            team_one.loses()
            team_two.wins()
        elif result == 'draw':
            team_one.draws()
            team_two.draws()

        teams[first] = team_one
        teams[second] = team_two

    ordered_teams = sorted(teams.values(), key=attrgetter('name'))
    ordered_teams = sorted(ordered_teams, key=attrgetter('points'), reverse=True)

    results = ['Team                           | MP |  W |  D |  L |  P']

    for team in ordered_teams:
        name = team.name.ljust(31)
        played = str(team.played).rjust(3).ljust(4)
        wins = str(team.won).rjust(3).ljust(4)
        draws = str(team.draw).rjust(3).ljust(4)
        loss = str(team.loss).rjust(3).ljust(4)
        points = str(team.points).rjust(3)
        results.append(f'{name}|{played}|{wins}|{draws}|{loss}|{points}')

    return '\n'.join(results)

