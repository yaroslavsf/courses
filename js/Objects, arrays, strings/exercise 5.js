function calc(str) {
    let y1, y2;
    let number1, number2;
    let resultNumber;
    let newStr = '';
    while (1) {
        let check = 1;
        for (let i = 0; i < str.length; i++) {
            if (str[i] == '*' || str[i] == '/') {
                check = 0;
            }
        }
        if (check == 1)
            break;

        for (let i = 0; i < str.length; i++) {
            switch (str[i]) {
                case '*':
                    number1 = '';
                    number2 = '';
                    y1 = i - 1;
                    while (y1 >= 0 && (str[y1] != '*' && str[y1] != '/' && str[y1] != '-' && str[y1] != '+')) {
                        number1 += str[y1];
                        y1--;
                    }
                    y2 = i + 1;
                    while (y2 < str.length && (str[y2] != '*' && str[y2] != '/' && str[y2] != '-' && str[y2] != '+')) {
                        number2 += str[y2];
                        y2++;
                    }
                    number1 = number1.split('').reverse().join('');
                    resultNumber = Number(number1) * Number(number2);
                    newStr = '';
                    for (let i = 0; i < str.length; i++) {
                        if (i - 1 == y1) {
                            newStr += resultNumber;
                            i += y2 - 1 - y1;
                        }
                        if (i != str.length)
                            newStr += str[i];
                    }
                    str = newStr;
                    break;

                case '/':
                    number1 = '';
                    number2 = '';
                    y1 = i - 1;
                    while (y1 >= 0 && (str[y1] != '*' && str[y1] != '/' && str[y1] != '-' && str[y1] != '+')) {
                        number1 += str[y1];
                        y1--;
                    }
                    y2 = i + 1;
                    while (y2 < str.length && (str[y2] != '*' && str[y2] != '/' && str[y2] != '-' && str[y2] != '+')) {
                        number2 += str[y2];
                        y2++;
                    }
                    number1 = number1.split('').reverse().join('');
                    resultNumber = Number(number1) / Number(number2);
                    newStr = '';
                    for (let i = 0; i < str.length; i++) {
                        if (i - 1 == y1) {
                            newStr += resultNumber;
                            i += y2 - 1 - y1;
                        }
                        if (i != str.length)
                            newStr += str[i];
                    }
                    str = newStr;
                    break;
            }
        }    
    }

    //-------

    while (1) {
        let check = 1;
        for (let i = 0; i < str.length; i++) {
            if (str[i] == '+' || str[i] == '-') {
                check = 0;
            }
        }
        if (check == 1)
            return str;

        for (let i = 0; i < str.length; i++) {
            switch (str[i]) {
                case '+':
                    number1 = '';
                    number2 = '';
                    y1 = i - 1;
                    while (y1 >= 0 && (str[y1] != '*' && str[y1] != '/' && str[y1] != '-' && str[y1] != '+')) {
                        number1 += str[y1];
                        y1--;
                    }

                    y2 = i + 1;
                    while (y2 < str.length && (str[y2] != '*' && str[y2] != '/' && str[y2] != '-' && str[y2] != '+')) {
                        number2 += str[y2];
                        y2++;
                    }
                    number1 = number1.split('').reverse().join('');             
                    resultNumber = Number(number1) + Number(number2);
                    newStr = '';
                    for (let i = 0; i < str.length; i++) {
                        if (i - 1 == y1) {
                            newStr += resultNumber;
                            i += y2 - 1 - y1;
                        }
                        if (i != str.length)
                            newStr += str[i];
                    }
                    str = newStr;          
                    break;
                case '-':
                    number1 = '';
                    number2 = '';
                    y1 = i - 1;
                    while (y1 >= 0 && (str[y1] != '*' && str[y1] != '/' && str[y1] != '-' && str[y1] != '+')) {
                        number1 += str[y1];
                        y1--;
                    }
                    y2 = i + 1;
                    while (y2 < str.length && (str[y2] != '*' && str[y2] != '/' && str[y2] != '-' && str[y2] != '+')) {
                        number2 += str[y2];
                        y2++;
                    }
                    number1 = number1.split('').reverse().join('');           
                    resultNumber = Number(number1) - Number(number2);
                    newStr = '';
                    for (let i = 0; i < str.length; i++) {
                        if (i - 1 == y1) {
                            newStr += resultNumber;
                            i += y2 - 1 - y1;
                        }
                        if (i != str.length)
                            newStr += str[i];
                    }
                    str = newStr;
                    // console.log(str)
                    break;
            }
        }  
    }
}


let str = calc("2+2*2");
console.log(str);