function nod(num1, num2)
{
    if (num1 > num2)
    return nod(num1-num2, num2);
    if (num1 < num2)
    return nod(num1 ,num2-num1);
    if (num1 == num2)
    return num1;
}

let a = prompt("������� ����� 1");
let b = prompt("������� ����� 2");

alert(nod(a,b));