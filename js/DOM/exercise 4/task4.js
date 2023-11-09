let text
let txtar = document.getElementById("story")
let container = document.querySelector(".container")

document.onkeydown = function (e) {
    e = e || window.event;//Get event
    if (e.ctrlKey) {
        let c = e.keyCode || e.keyCode;//Get key code
        switch (c) {
            case 69://Block Ctrl+e          
                e.preventDefault();     
                e.stopPropagation();
                text = container.innerHTML
                txtar.value = text
                container.style.display = "none"
                txtar.style.display = "block"
            break;
            case 83://Block Ctrl+s
                e.preventDefault();     
                e.stopPropagation();               
                text = txtar.value
                // document.body.children[0].remove()                         
                container.style.display = "block"
                txtar.style.display = "none"
                // console.log(document.body.children[0])
                // container.innerHTML = text
                container.innerHTML = text
            break;
        }
    }
};
