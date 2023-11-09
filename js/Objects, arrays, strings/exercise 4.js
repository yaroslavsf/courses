let arr = [
    {
        name: "������� �����",
        sits: 10,
        faculty: "����������������",
    },
    {
        name: "������� ���������",
        sits: 20,
        faculty: "����������������",
    },
    {
        name: "�������� ���������",
        sits: 18,
        faculty: "������",
    }

]
//1
function outputArray(array) {
    for (iterator of array) {
        console.log(iterator.name, iterator.sits, iterator.faculty)
    }
}
//2
function outputArrayByFaculty(array, faculty) {
    for (iterator of array) {
        if (iterator.faculty === faculty)
            console.log(iterator.name, iterator.sits, iterator.faculty)
    }
}
//3
let group = {
    name: "��011",
    students: 12,
    faculty: "����������������"
}

function outputArrayForGroup(array, group) {
    for (iterator of array) {
        if (iterator.faculty === group.faculty && (group.students <= iterator.sits)) {
            console.log(iterator.name, iterator.sits, iterator.faculty)
        }
    }
}
//4
function sortArrBySits(array) {
    array.sort((a, b) => a.sits > b.sits ? -1 : 1);
}
//5
function sortArrByName(array) {
    array.sort((a, b) => a.name > b.name ? 1 : -1);
}



//1 
// outputArray(arr);
//2
// outputArrayByFaculty(arr, "������");
//3 
// outputArrayForGroup(arr, group)
//4
// sortArrBySits(arr);
//5 
//sortArrByName(arr);