let input1 = prompt("Ââåäèòå 1 ãğàíèöó äëÿ ïîñ÷¸òà ñóììû âñåõ ÷èñåë");
let input2 = prompt("Ââåäèòå 2 ãğàíèöó äëÿ ïîñ÷¸òà ñóììû âñåõ ÷èñåë");

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

alert(`Ñóììà: ${sum}`);