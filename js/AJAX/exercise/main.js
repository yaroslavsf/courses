const profileContainer = document.getElementById('cardsContainer')
const searchForm = document.forms[0]

class ProfileCard {
    constructor(obj) {
       this.userId = obj.userId
       this.id = obj.id
       this.title = obj.title
       this.body = obj.body
    }

    
    render(container) {
        container.innerHTML += `
        <div class="col-md-3 mt-3">
        <div class="card mb-2">
            <div class="card-body">
                <h5 class="card-title">user id: ${this.userId}</h5>
                <ul class="list-group list-group-flush">
                    <li class="list-group-item">id: ${this.id}</li>
                    <li class="list-group-item">title: ${this.title}</li>
                    <li class="list-group-item">body: ${this.body}</li>
                </ul>
            </div>  
        </div>
    </div>
       `

    }
}

searchForm.addEventListener('submit', e => {
    e.preventDefault()
    const xml = new XMLHttpRequest()

    searchQuery = document.getElementById('exampleInput').value
    console.log(searchQuery)    

    xml.open('GET', `https://jsonplaceholder.typicode.com/posts?title_like=${searchQuery}`, true)
    xml.send(null)
    xml.onreadystatechange = function () {
        switch (this.readyState) {
            case 3:
                console.log('loading')
                break;
            case 4:
                const response = JSON.parse(this.responseText)
                switch (this.status) {
                    case 200:
                        console.log(response)

                        console.log(profileContainer.childNodes[3])

                        profileContainer.childNodes[1].innerHTML = ' '
                        profileContainer.childNodes[3].innerHTML = ' '
                        profileContainer.childNodes[5].innerHTML = ' '


                        // console.log(profileContainer)
                        let counter = 0
                        for (const key in response) {
                            console.log(counter)
                            if (counter == 0)
                            new ProfileCard(response[key]).render(profileContainer.childNodes[1])
                            else if (counter == 1) 
                            new ProfileCard(response[key]).render(profileContainer.childNodes[3])
                            else if (counter == 2)
                            new ProfileCard(response[key]).render(profileContainer.childNodes[5])
                            counter++
                            if (counter == 3) counter = 0
                        }
                        
                        // console.log(response)
                        break;
                    case 404:
                        alert(`${response.status}`)
                        break;
                }
                // console.log(this.responseText)
                break;
        }
    }
    // xml.onerror = function() {
    //     console.log(this.status, this.statusText, this.responseText)    
    // }
    // xml.onload = function () {

    // }
})
















































//xml http request
// const xml = new XMLHttpRequest()

// xml.open('GET', 'person.json', true)
// xml.send(null)//потому что get запрос(у него нету тела, а только url-параметры)
// xml.onreadystatechange = function() {
//     switch(xml.readyState) {
//         case 3: 
//             document.write('loading')
//         break;
//         case 4:
//              document.write(xml.status, xml.statusText,  xml.responseText)
//         break;
//     }
// }

// xml.timeout = 1000

// xml.onload = function() {

//    document.write(xml.responseText)
// }

// xml.onerror = function(e) {
// console.log(e)
// }
