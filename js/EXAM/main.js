class App {
    #sortButtons =
        [
            { DOMq: document.querySelector('#place'), isSorted: 0 },
            { DOMq: document.querySelector('#team'), isSorted: 0 },
            { DOMq: document.querySelector('#matches'), isSorted: 0 },
            { DOMq: document.querySelector('#win'), isSorted: 0 },
            { DOMq: document.querySelector('#withdraw'), isSorted: 0 },
            { DOMq: document.querySelector('#lose'), isSorted: 0 },
            { DOMq: document.querySelector('#goals'), isSorted: 0 },
            { DOMq: document.querySelector('#conceded-goals'), isSorted: 0 },
            { DOMq: document.querySelector('#score'), isSorted: 0 }
        ]

    constructor(rootContainer) {
        this.teams = []
        this.rootContainer = rootContainer
        this.sortBy = ["place", "team", "matches", "win", "withdraw", "lose", "goals", "conceded-goals", "score"]
        this.init()
        this.initSortButtons()
    }

    initSortButtons() {
        for (const iterator of this.#sortButtons) {
            iterator.DOMq.addEventListener('click', () => {
                switch (iterator.DOMq.id) {
                    case "place":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByPlace(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByPlace(-1)
                        }
                        break;
                    case "team":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByTeam(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByTeam(-1)
                        }
                        break;
                    case "matches":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByMatches(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByMatches(-1)
                        }
                        break;
                    case "win":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByWins(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByWins(-1)
                        }
                        break;
                    case "withdraw":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByWithdraws(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByWithdraws(-1)
                        }
                        break;
                    case "lose":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByLoses(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByLoses(-1)
                        }
                        break;
                    case "goals":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByGoals(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByGoals(-1)
                        }
                        break;
                    case "conceded-goals":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByCGoals(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByCGoals(-1)
                        }
                        break;
                    case "score":
                        if (iterator.isSorted) {
                            iterator.isSorted = 0
                            this.sortByScore(1)
                        } else {
                            iterator.isSorted = 1
                            this.sortByScore(-1)
                        }
                        break;

                }
            })
        }
    }

    reRender() {
        let container = document.querySelector('.teams-container')
        container.innerHTML = ' '
        this.renderTeams()
    }

    sortByPlace(mode) {
        this.teams = this.teams.sort((a, b) => a.place > b.place ? 1 : -1)
        for (const iterator of this.#sortButtons) {
            iterator.isSorted = 0;
        }
        this.reRender()
    }

    sortByTeam(mode) {
        this.teams = this.teams.sort((a, b) => a.name > b.name ? -1 * (mode) : 1 * (mode))
        this.reRender()
    }

    sortByMatches(mode) {
        this.teams = this.teams.sort((a, b) => a.matches > b.matches ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByWins(mode) {

        this.teams = this.teams.sort((a, b) => a.win > b.win ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByWithdraws(mode) {

        this.teams = this.teams.sort((a, b) => a.draw > b.draw ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByLoses(mode) {

        this.teams = this.teams.sort((a, b) => a.lose > b.lose ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByGoals(mode) {

        this.teams = this.teams.sort((a, b) => a.goals > b.goals ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByCGoals(mode) {
        this.teams = this.teams.sort((a, b) => a.conceded_goals > b.conceded_goals ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    sortByScore(mode) {
        this.teams = this.teams.sort((a, b) => a.score > b.score ? 1 * (mode) : -1 * (mode))
        this.reRender()
    }

    renderTeams() {
        for (let i = 0; i < this.teams.length; i++) {
            let color = ""
            if (this.teams[i].color == 1) {
                color = "background-color: rgb(127, 212, 152)"
            } else if (this.teams[i].color == 2) {
                color = "background-color: rgb(204, 238, 214)"
            } else if (this.teams[i].color == 4) {
                color = "background-color: rgb(255, 153, 177)"
            }
            this.teams[i].renderTeam(this.rootContainer, color)

        }
    }

    init() {

        const url = `http://127.0.0.1:5500/seriea.json`;
        const $this = this
        fetch(url)
            .then((resp) => resp.json())
            .then(function (response) {
                for (const key in response.teams) {
                    const tempTeam = new Team(response.teams[key])
                    $this.teams.push(tempTeam)
                }
                $this.maxPlace = $this.teams[$this.teams.length-1].place

                $this.renderTeams();
            })
            .catch(function (error) {
                console.log(error);
            });
    }
}

class Team {
    constructor(obj) {
        this.name = obj.name
        this.flag_country = obj.flag_country
        this.tag_url = obj.tag_url
        this.matches = obj.matches
        this.win = obj.win
        this.draw = obj.draw
        this.lose = obj.lose
        this.score = obj.score
        this.goals = obj.goals
        this.conceded_goals = obj.conceded_goals
        this.place = obj.place
        this.color = obj.color
    }



    renderTeam(root, color) {
        root.innerHTML +=
            `
        <tr class="container-fluid">
            <td class="place" style="${color}">${this.place}</td>
            <td class="team"><img src="italian.png"> ${this.name} </td>
            <td class="matches">${this.matches}</td>
            <td>${this.win}</td>
            <td>${this.draw}</td>
            <td>${this.lose}</td>
            <td>${this.goals}</td>
            <td>${this.conceded_goals}</td>
            <td class="color-score">${this.score}</td>
        </tr> 
        `
    }
}

const app = new App(document.querySelector('.teams-container'));

