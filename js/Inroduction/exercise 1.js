let sum = prompt("������� ����� ����� � ��������");
let pricePerOne = prompt("������� ���� �� ���� �������");
let numberOfChockolates = sum/pricePerOne - sum/pricePerOne%1; 

alert(`�������� ����� ������: ${numberOfChockolates} \n�����: ${sum%pricePerOne}`);