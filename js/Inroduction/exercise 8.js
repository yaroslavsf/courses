function isPefect(number)
{
    let sum = 0;
    for ( let i = 1; i < number; i++ )
    {
        if ( number % i == 0 )  // ���� ������� ��� �������
        {
            sum += i;
        }
    }
    return (sum == number ? "�����������" : "�� �����������");
}


let a = prompt("������� �����");
alert(isPefect(a));