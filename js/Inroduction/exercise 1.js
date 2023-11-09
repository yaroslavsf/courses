let sum = prompt("¬ведите сумму денег в кошельке");
let pricePerOne = prompt("¬ведите цену за одну единицу");
let numberOfChockolates = sum/pricePerOne - sum/pricePerOne%1; 

alert(`Ўоколада можно купить: ${numberOfChockolates} \n—дача: ${sum%pricePerOne}`);