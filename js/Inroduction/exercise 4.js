function myRound(variable)
{
    return variable - (variable%1);
}

let number = prompt("Введите число");
let n1 = myRound(number%10), n2 = myRound(number/10%10), n3 = myRound(number/100);
if (n1 != n2 && n2 != n3 && n3 != n1)
{
    alert("Повторных цифр нету");
}
else{
    alert("Повторные цифры есть");
}