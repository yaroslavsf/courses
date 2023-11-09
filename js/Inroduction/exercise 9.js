function myPow(num, power)
{
    if (power == 0)
        return 1;
    if (power <= 1)
    return num;
    num*=num;
    return myPow(num, power-1);
}

let a = prompt("¬ведите число");
alert(myPow(a,2));