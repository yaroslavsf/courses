function checkEven(value)
{
    return (value%2==0) ? "Чётное" :  "Не чётное";
}



let number = prompt("Введите число");
alert( checkEven(number) );