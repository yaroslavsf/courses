// 1. Подключите jQuery, убедитесь в доступности объекта -библиотеки. Примечание: попробуйте подключение с разных CDN-хранилищ, и при помощи локального файла
// 2. Откройте верстку http://codepen.io/htmllab/pen/NNaGOV
// Выберите при помощи селекторов jQuery
// 1 — все HTML-элементы strong и окрасьте их в зеленый цвет
// 2 — найдите все HTML-элементы em и добавьте им класс .selected
// 3 — Найдите все элементы mark, которые находятся в div с классом row и задайте им класс .selected
// 4 — Найдите все гиперссылки и удалите у них подчеркивания
// 5 — Найдите все HTML-элементы, который содержат слово «Задания» и находятся в элементе с классом .container
// 6 — Переключите элементы strong с классом some в состояние без этого класса, а тем элементам (strong), у которых небыло этого класса — добавьте.
// 7 — среди набора элементов с классом .row удалите класс у второго элемента
// 8 — прочитайте CSS-свойство color у второй гиперсылки в тексте


//1
// const array = ($('strong'))
// array.css('background', 'green')

//2
// $('em').addClass('selected');

//3
// $('.row').find('div').find('mark').addClass('selected')

//4 undone
// let a = ($('a'))
// a.attr('href')
// console.log(a.attr('href',null))

//5
// console.log($("container:contains('Задания')"))

//6
// let a = $('strong > some')
// let b = $('strong')

// 7
// let a =$('.row:eq(1)')
// console.log(a)
// a.removeClass('row')

//8
// let a = $('a:eq(1)').css('color')
// console.log(a)
