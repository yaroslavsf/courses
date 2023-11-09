function getNumberOfDigits(number)
{
    let count = 0;
    while (number > 0)
    {
        count++;
        number = number / 10 - (number/10%1);
    }
    return count;
}

let a = prompt("Введите число");

alert(`Количество цифр: ${getNumberOfDigits(a)}`);