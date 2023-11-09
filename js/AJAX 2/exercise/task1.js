const usersContainer = document.getElementById('users_container')
const usersForm = document.forms[0]
const loader = document.getElementById('loader')
const pagContainer = document.getElementById('pag_container')
loader.style.display = 'none'
let pagResult = ''

class UserCard {
    constructor(obj) {
        this.userId = obj.userId
        this.id = obj.id
        this.title = obj.title
        this.body = obj.body
    }

    renderUser(container) {
        container.innerHTML += `
        <div class="col-md-3">
        <div class="card m-2">
            <div class="card-body">
                <h5 class="card-title">${this.id}</h5>
                <ul class="list-group list-group-flush">
                    <li class="list-group-item">User-id: ${this.userId}</li>
                    <li class="list-group-item">title: ${this.title}</li>
                    <li class="list-group-item">body: ${this.body}</li>
                </ul>
            </div>
        </div>
    </div>
        `
    }
}



class Api {
    #currentPage = 1
    #baseUrl = 'https://jsonplaceholder.typicode.com/posts?_start=0&_end=25'
    #page1 = document.querySelector('.page-item1')
    #page2 = document.querySelector('.page-item2')
    #page3 = document.querySelector('.page-item3')
    #page4 = document.querySelector('.page-item4')
 
    #next = document.querySelector('.next')
    #prev = document.querySelector('.previous')
    
  

    constructor(recordsPerPage = 25) {
        this.recordsPerPage = recordsPerPage
        this.userCard = null
        this.userCards = []
        this.loadElements()
     
        this.#page1.addEventListener('click', ()=> {
            this.#currentPage = 1
            console.log(this.#currentPage)
            this.loadNewPage()  
        })
        this.#page2.addEventListener('click', ()=> {
            this.#currentPage = 2
            this.loadNewPage()  
        })
        this.#page3.addEventListener('click', ()=> {
            this.#currentPage = 3
            this.loadNewPage()  
        })
        this.#page4.addEventListener('click', ()=> {
            this.#currentPage = 4
            this.loadNewPage()  
        })


        this.#next.addEventListener('click', ()=> {
         if (this.#currentPage < 4)
         this.#currentPage++
         this.loadNewPage()  
        })
        this.#prev.addEventListener('click', ()=> {
            if (this.#currentPage > 1)
            this.#currentPage--
            this.loadNewPage()  
        })
    }


    loadNewPage() {
            loader.style.display = 'flex'

            const xml = new XMLHttpRequest()
            let pages1, pages2
            switch (this.#currentPage) {
                case 1:
                    pages1 = 0
                    pages2 = 25
                    break;
                case 2:
                    pages1 = 25
                    pages2 = 50
                    break;
                case 3:
                    pages1 = 50
                    pages2 = 75
                    break;
                case 4:
                    pages1 = 75
                    pages2 = 100
                    break;
            }
            xml.open('GET', `https://jsonplaceholder.typicode.com/posts?_start=${pages1}&_end=${pages2}`)
            xml.send(null)
            xml.onload = function () {
                setTimeout(() => {
                    loader.style.display = 'none'
                }, 1000)
                const response = JSON.parse(this.responseText) || []            
                usersContainer.innerHTML = ' '

             
                for (const iterator of response) {

                    let newUser = new UserCard(iterator)
                    newUser.renderUser(usersContainer) 
                }
            }
            xml.onerror = function () {
                alert(this.status, this.responseText)
            }
        
    }


    loadElements() {
        const xml = new XMLHttpRequest()
        const $this = this
        xml.open('GET', `${this.#baseUrl}/posts?_start=0&_end=25}`, true)

        xml.send()

        xml.onreadystatechange = function () {
            switch (this.readyState) {
                case 3:
                    loader.style.display = 'flex'
                    break
                case 4:
                    setTimeout(() => {
                        loader.style.display = 'none'
                    }, 1000)
                    const response = JSON.parse(this.responseText)
                    switch (this.status) {
                        case 200:
                            for (let i = 0; i < response.length; i++) {
                                $this.userCard = new UserCard(response[i])
                                $this.userCard.renderUser(usersContainer)
                                $this.userCards.push($this.userCard)
                            }
                            const usersPageCount = 25
                            pagResult = ''
                            for (let i = 0; i < usersPageCount; i++) {
                                pagResult += `<li class="page-item"><a class="page-link" href="#">${i + 1}</a></li>`
                            }
                            let usersListHtml = ''
                            for (const iterator of response) {
                                usersListHtml += `
                            <div class="col-md-3">
                                <div class="card m-2">
                                    <div class="card-body">
                                        <h5 class="card-title">${iterator.id}</h5>
                                        <ul class="list-group list-group-flush">
                                            <li class="list-group-item">User-id: ${iterator.userId}</li>
                                            <li class="list-group-item">title: ${iterator.title}</li>
                                            <li class="list-group-item">body: ${iterator.body}</li>
                                        </ul>
                                    </div>
                                </div>
                            </div>
                            `
                         }
                            usersContainer.innerHTML = usersListHtml
                            break;
                        case 404:   
                            // handle errors (if user not found)
                            alert(`${this.status}, ${response.message}`)
                            break;
                    }
                    break
            }
        }
    }

   





}




api = new Api()
