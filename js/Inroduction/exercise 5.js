let input1 = prompt("������� 1 ������� ��� ������� ����� ���� �����");
let input2 = prompt("������� 2 ������� ��� ������� ����� ���� �����");

let limit1, limit2;
if (input1 > input2) {
    limit1 = input2;
    limit2 = input1;
} else {
    limit2 = input2;
    limit1 = input1;
}


let sum = 0;
for (let i = Number(limit1); i <= limit2; i++)
{
    sum += i;
}

alert(`�����: ${sum}`);