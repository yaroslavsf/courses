function checkAge()
{
    return (age >= 0 && age <= 12) ? ("�� �������") : 
    (age >= 10 && age <= 18) ? ("�� ���������") :
    (age >= 18 && age <= 60) ? ("�� ��������") :
    (age >= 60) ? ("�� ��������") : ("���������� �������");
 
}

let age = prompt("������� ��� �������");
 alert(checkAge(age));