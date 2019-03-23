/*
 * Implement all your JavaScript in this file!
 */

 var displayField = $('#display');

 var ope1 = '';
 var ope2 = '';
 var opt = '';

function handler (event) {
    var target = event.target.innerHTML;
    if (target === 'C')   {
        displayField.val('');
        ope1 = '';
        ope2 = '';
        opt = '';
    }
    else if (target === '=') {
        if (ope1 === '') {
            displayField.val('');
        }
        else if (ope1 !== '' && opt === '') {
            displayField.val(ope1);
        }
        else if (ope1 !== '' && opt !== '' && ope2 === '') {
            displayField.val(opt);
        }
        else if (ope1 !== '' && ope2 !== '') {
            ope1 = operatorHandler(ope1, ope2, opt);
            displayField.val(ope1);
            ope2 = '';
            opt = '';
        }
    }
    else if (isNaN(target)) {
        //when using an Operator or =
        if (ope1 === '') {
            displayField.val('');
        }
        else if (ope1 !== '' && opt !== '' && ope2 !== '') {
            ope1 = operatorHandler(ope1, ope2, opt);
            displayField.val(ope1);
            ope2 = '';
            opt = target;
        }
        else {
            opt = target;
            displayField.val(target);
        }
    }
    else {
        if (ope1 === '' || opt === '') {
            ope1 = ope1 + target;
            displayField.val(ope1);
        }
        else if (opt !== '') {
            ope2 = ope2 + target;
            displayField.val(ope2);
        }
    }
}

function operatorHandler (num1, num2, op) {
    var result = 0;
    var a = Number(num1);
    var b = Number(num2);
    if (op === '+') {
        result = a + b;
        return result.toString();
    }
    else if (op === '-') {
        if (a > b) {
            result = a - b;
        }
        else {
            result = (-1) * (b - a);
        }
        return result.toString();
    }
    else if (op === '*') {
        result = a * b;
        return result.toString();
    }
    else if (op === '/') {
        if (b !== 0) {
            result = a / b;
            return result.toString();
        }
        else {
            return 'infinity';
        }
    }
}
$('td').click(handler);
