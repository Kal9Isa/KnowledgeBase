/*
 * Implement all your JavaScript in this file!
 */

 var displayField = $('#display');

 var ope1 = '';
 var ope2 = '';
 var opt = '';

//handling the click event

function handler (event) {
    // Track the HTML content of the clicked button
    var target = event.target.innerHTML;
    
    // When Clear button is used
    if (target === 'C')   {
        displayField.val('');
        ope1 = '';
        ope2 = '';
        opt = '';
    }
    
    // When equals button is pressed which is supposed to be ignored if there's no operand nor an operator.
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
    
    // When the clicked button is an operator + - / *, which pressing operators repeatedly is supposed
    // to update the operator to the latest entry, and pressing an operator after an operation is 
    // designed to keep the operation going.
    else if (isNaN(target)) {
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
    
    // When entering numbers by pressing buttons
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

// Handling operations with given operands
function operatorHandler (num1, num2, op) {
    var result = 0;
    var a = Number(num1);
    var b = Number(num2);
    if (op === '+') {
        result = a + b;
    }
    else if (op === '-') {
        if (a > b) {
            result = a - b;
        }
        else {
            result = (-1) * (b - a);
        }
    }
    else if (op === '*') {
        result = a * b;
    }
    else if (op === '/') {
        if (b !== 0) {
            result = a / b;
        }
        else {
            return 'infinity';
        }
    }
    return result.toString();
}

// Event listener for <td> element which wraps all the buttons
$('td').click(handler);
