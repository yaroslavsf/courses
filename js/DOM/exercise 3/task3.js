// let lines = document.querySelectorAll('li');
// lines.forEach((element) => {
//     element.onmousedown = make_orange;
// });

// let last_line;

// function make_orange() {

//     if (event.shiftKey) {
//         if (last_line.rowIndex < this.rowIndex) {
//             for (let i = last_line.rowIndex; i <= this.rowIndex; i++) {
//                 lines[i].classList.add('pointed');
//             }
//         }
//         else {
//             for (let i = last_line.rowIndex; i >= this.rowIndex; i--) {
//                 lines[i].classList.add('pointed');
//             }
//         }
//         return;
//     }
//     if (event.ctrlKey) {
//         if (this.classList.contains('pointed')) {
//             this.classList.remove('pointed');
//             return;
//         }
//         else {
//             this.classList.add('pointed');
//             return;
//         }
//     }

//     document.querySelectorAll('.pointed').forEach((elem) => {
//         elem.classList.remove('pointed');
//     });

//     if (!this.classList.contains('pointed')) {
//         this.classList.add('pointed');

//     }
//     if (this.classList.contains('pointed')) {
//         last_line = this;
//         return;
//     }
// }
const list = [...document.getElementsByTagName('li')]
const marked = []

let shiftB1, shiftB2

for (const iterator of list) {
    iterator.addEventListener('click', e => {
        if (e.target.style.backgroundColor != "orange")
        e.target.style.backgroundColor = "orange"
        else
        e.target.style.backgroundColor = "transparent"


        if (e.shiftKey === true) {
            for (const iterator2 of list) {
                if (iterator2.style.backgroundColor === "orange") {

                    let indexBegin, indexEnd
                    for (let i = 0; i < list.length; i++) {
                        if (list[i] === iterator)  
                        indexBegin = i
                        if (list[i] === iterator2)
                        indexEnd = i
                    }
                   

                    if (indexBegin > indexEnd)
                    [indexBegin, indexEnd] = [indexEnd, indexBegin]

              
                    while (indexBegin < indexEnd) {
                        list[indexBegin].style.backgroundColor = 'orange'
                        console.log(list[indexBegin])

                        indexBegin++
                    }
                    
                    
                    break
                }
            }
        }

        if (e.ctrlKey !== true) {
            for (const iterator2 of list) {
                if (iterator != iterator2) {
                    iterator2.style.backgroundColor = "transparent"
                }
            }
        }

       

    })
}
