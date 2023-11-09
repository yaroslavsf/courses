let listOfProducts = [
   {
   name:"apple",
   number: 5,
   isBought: false,
   },
   {
   name:"banana",
   number: 3,
   isBought: true,
   }
];
//1
function outputList(list) {
   let listCopy = [...list];   
   listCopy.sort((a, b) => a.isBought > b.isBought ? -1 : 1);
   for (obj of listCopy) {
      console.log(obj.name, obj.number, obj.isBought);
   }
} 

//2
let bananaToAdd = {
   name:"banana",
   number: 5,
   isBought: true,
}

function addProduct(product, list) {
   for (obj of list) {
      if (product.name == obj.name) {
         obj.number += product.number;
         return;
      }
   }

   list.push(product)
}

//3
function buyProduct(nameOfProduct)
{
   for (obj of listOfProducts) {
      if (nameOfProduct == obj.name) {
         obj.isBought = true;
         return;
      }
   }
}

// outputList(listOfProducts);                      //1
// addProduct(bananaToAdd, listOfProducts);         //2
// buyProduct("apple");                             //3