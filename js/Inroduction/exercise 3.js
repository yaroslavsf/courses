function checkAge()
{
    return (age >= 0 && age <= 12) ? ("Вы ребенок") : 
    (age >= 10 && age <= 18) ? ("Вы подросток") :
    (age >= 18 && age <= 60) ? ("Вы взрослый") :
    (age >= 60) ? ("Вы пенсонер") : ("Интересный возраст");
 
}

let age = prompt("Введите ваш возраст");
 alert(checkAge(age));