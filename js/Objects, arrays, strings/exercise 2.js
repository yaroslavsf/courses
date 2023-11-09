/ let obj = {
//    numerator:5, //числитель
//    denominator:2,//знаменатель
//    reduce() {
//       let nodf = this.nod(this.numerator, this.denominator);
//       this.denominator /= nodf;
//       this.numerator /= nodf;
//    },

//    nod(num1, num2) {
//       if (num1 < 0 && num2 < 0)
//       return 1;

//        if (num1 > num2)
//        return this.nod(num1-num2, num2);
//        if (num1 < num2)
//        return this.nod(num1 ,num2-num1);
//        if (num1 == num2)
//        return num1;
//    },

//    nok(num1, num2) { 
//       return num1*num2 / this.nod(num1,num2); 
//    },

//    add(num, den) {      //2 5
//       if (den === this.denominator) {
//          this.numerator += num;
//       } 
//       else {
//          let temp = this.denominator; //2
//          let sameDen = this.nok(this.denominator, den); //10
//          num = num * (sameDen/den);
//          this.numerator *= sameDen/temp;
//          this.numerator += num;
//          this.denominator = sameDen;
//       }
//       this.reduce();
//    },

//    sub(num, den) {
//       if (den === this.denominator) {
//          this.numerator -= num;
//       }
//       else {  
//          let temp = this.denominator; //2
//          let sameDen = this.nok(this.denominator, den); //10
//          num = num * (sameDen/den);
//          this.numerator *= sameDen/temp;
//          this.numerator -= num;
//          this.denominator = sameDen;
//       }
//       this.reduce();
//    },

//    mult(num, den) {
//       this.numerator *= num;
//       this.denominator *= den;

//       let sameDivN = this.nod(this.numerator, this.denominator);

//       this.numerator /= sameDivN;
//       this.denominator /= sameDivN;
//       this.reduce();
//    },

//    div(num, den) {
//       this.numerator *= den;
//       this.denominator *= num;

//       let sameDivN = this.nod(this.numerator, this.denominator);

//       this.numerator /= sameDivN;
//       this.denominator /= sameDivN;
//       this.reduce();
//    },
// }

// obj.sub(2,5)
// alert(`${obj.numerator} / ${obj.denominator}`); // 2.1
// console.log(obj)

// obj.add(2,5)
// alert(`${obj.numerator} / ${obj.denominator}`); // 2.9

// obj.mult(5,2)
// alert(`${obj.numerator} / ${obj.denominator}`); //    25/4

// obj.div(5,2)
// alert(`${obj.numerator} / ${obj.denominator}`); 

