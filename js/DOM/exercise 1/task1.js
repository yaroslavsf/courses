function isLink(ref) {
    let str = ref.innerHTML;
    let ht = 'http://';
    let hts = 'https://';
 
    let success = 1;
 
    for (let i = 0; i < 7; i++) {//http
       if (str[i] != hts[i])
          success = 0;
    }
 
    if (success == 1)
       return 1;
 
    for (let i = 0; i < 6; i++) {//https
       if (str[i] != ht[i])
          return 0;
    }
 
    return 1;
 }
 
 let lists = [...document.getElementsByTagName('li')];
 console.log(lists);
 
 
 document.addEventListener("DOMContentLoaded", function () {
 
    for (let i = 0; i < lists.length; i++) {
       if (isLink(lists[i]) == 1) {
          lists[i].style.borderBottomStyle = "dashed";
       }
    }
 })
 