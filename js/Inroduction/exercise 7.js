function compare(n1, n2)
{
    if (n1 < n2){
        return -1; 
    }else if (n1 > n2){
        return 1;
    }else{
        return 0;
    }
}

let a = prompt("¬ведите первое число");
let b = prompt("¬ведите второе число");
alert(compare(a,b));