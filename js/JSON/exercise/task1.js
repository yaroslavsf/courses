const peopleData = JSON.parse(PEOPLE_DATA)

class App {
    constructor(rootContainer, peopleData) {
        this.peopleList = []
        this.rootContainer = rootContainer
        this.addForm = document.querySelector('.add-form')
        this.sortBtn = document.querySelector('#sortBtn')
        console.log(this.sortBtn)
        this.init(peopleData)
    }

    get peopleContainer() {
        return this.rootContainer.children[0].children[1]
    }
    
    reRender() {
        let tbody = [...document.getElementsByTagName('tbody')]
        tbody[0].innerHTML = ' '
        for (const key in this.peopleList) {
               this.peopleList[key].render(this.peopleContainer) 
        }
    }

    sortAge(typeOfSort) { //1 / -1
        if (typeOfSort === 1)
        this.peopleList = this.peopleList.sort((a, b) => a.birthDate > b.birthDate ? -1 : 1)
        else
        this.peopleList = this.peopleList.sort((a, b) => a.birthDate > b.birthDate ? 1 : -1)
        this.reRender()
    }
    
    sortFirstname(typeOfSort) {
        if (typeOfSort === 1)
        this.peopleList = this.peopleList.sort((a, b) => a.firstname > b.firstname ? -1 : 1)
        else
        this.peopleList = this.peopleList.sort((a, b) => a.firstname > b.firstname ? 1 : -1)
        this.reRender()
    }

    sortLastname(typeOfSort) {
        if (typeOfSort === 1)
        this.peopleList = this.peopleList.sort((a, b) => a.lastname > b.lastname ? -1 : 1)
        else
        this.peopleList = this.peopleList.sort((a, b) => a.lastname > b.lastname ? 1 : -1)
        this.reRender()
    }

    sortId(typeOfSort) {
        if (typeOfSort === 1)
        this.peopleList = this.peopleList.sort((a, b) => a.id > b.id ? -1 : 1)
        else
        this.peopleList = this.peopleList.sort((a, b) => a.id > b.id ? 1 : -1)
        this.reRender()
    }

    sortCountry(typeOfSort) {
        if (typeOfSort === 1)
        this.peopleList = this.peopleList.sort((a, b) => a.country> b.country ? -1 : 1)
        else
        this.peopleList = this.peopleList.sort((a, b) => a.country > b.country ? 1 : -1)
        this.reRender()
    }

    sort() {
       
        this.sortBtn.addEventListener('click', () => {
            let select1 = document.querySelector('#sel1')
            let select2 = document.querySelector('#sel2')
           
            switch(select1.value) {
                case 'id':
                    if (select2.value == 'esc') {
                        this.sortId(1) 
                        } else {           
                            this.sortId(-1)
                        }
                    break;
                case 'firstname':
                    if (select2.value == 'esc') {
                        this.sortFirstname(1) 
                        } else {           
                            this.sortFirstname(-1)
                        }
                    break;
                case 'lastname':
                    if (select2.value == 'esc') {
                        this.sortLastname(1) 
                        } else {           
                            this.sortLastname(-1)
                        }
                    break;
                case 'age':
                    if (select2.value == 'esc') {
                        this.sortAge(1) 
                        } else {           
                            this.sortAge(-1)
                        }
                    break;    
                case 'country':
                    if (select2.value == 'esc') {
                        this.sortCountry(1) 
                        } else {           
                            this.sortCountry(-1)
                        }
                    break;
                
            }

        }) 
    }

    init() {
        this.sort()
        let counter = 0
        for (const p of peopleData) {
            const person = new Person(p.id, p.firstname, p.lastname, p.birth_date, p.country)
            this.peopleList.push(person)
            person.render(this.peopleContainer, counter)
            counter++
        }
        this.bindEvents(counter)
    }

  
    getInputValue(e, key) {
        return e.target.elements[key]?.value
    }

    handlePersonAdd(e) {
        e.preventDefault()
        const id = this.getInputValue(e, 'id')
        const firstname = this.getInputValue(e, 'firstname')
        const lastname = this.getInputValue(e, 'lastname')
        const birthDate = this.getInputValue(e, 'birth_date')
        const country = this.getInputValue(e, 'country')  
        const newPerson = new Person(id,firstname,lastname,birthDate,country)
        this.peopleList.unshift(newPerson) 

        newPerson.render(this.peopleContainer)
    }

    bindEvents(counter) {
        this.addForm.addEventListener('submit', this.handlePersonAdd.bind(this))
    }
}


class Person {
    constructor(id = '', firstname = '', lastname = '', birthDate = new Date(), country = '') {
        this.id = id
        this.firstname = firstname
        this.lastname = lastname
        const dateNow = new Date()
        if (birthDate != dateNow) {
        this.birthDate = birthDate.split('-')
        this.birthDate = dateNow.getFullYear() - this.birthDate[0]
        }
        this.country = country
    }



    render(root, index) {
        
        root.insertAdjacentHTML('afterbegin',  `
     <tr class='row-${index}'>
        <td scope="row" class="table-active">${this.id}</td>
        <td>${this.firstname}</td>
        <td>${this.lastname}</td>
        <td>${this.birthDate}</td>
        <td>${this.country}</td>
        <td><input type="hidden" value="${index}" name="id" /><button class="btn btn-danger form-${index}">Delete</button></td>
        
     </tr>
       `);
}

}

document.addEventListener('click', e => {
    const str = [...e.target.classList].join(' ')
    if (str.includes('form-')) {
        if ( document.querySelector(`.row-${str.match(/\d+/g)?.[0]}`) != null)
        document.querySelector(`.row-${str.match(/\d+/g)?.[0]}`).remove()
    }
})

new App(document.querySelector('.wrapper'), peopleData)