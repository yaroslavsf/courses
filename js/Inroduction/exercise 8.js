function isPefect(number)
{
    let sum = 0;
    for ( let i = 1; i < number; i++ )
    {
        if ( number % i == 0 )  // если делится без остатка
        {
            sum += i;
        }
    }
    return (sum == number ? "Совершенное" : "Не совершенное");
}


let a = prompt("Введите число");
alert(isPefect(a));