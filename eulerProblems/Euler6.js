// JavaScript source code
/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/


//euler module
exports.euler = function(n){

var squareOfSum = function () {
    var sum = 0;
    for (var i = 1; i <= n; i++) {
        sum = sum + i;
    }

    var square = Math.pow(sum, 2);
    console.log("I am squareOfSum: " + square);
    return  square;
};


var sumOfSquares = function () {
    var sum = 0;
    for (var i = 1; i <= n; i++) {
        sum = sum + Math.pow(i, 2);
    }

    console.log("I am sumOfSquares: " + sum);
    return sum;
};

var result = (squareOfSum()-sumOfSquares()).toString();
result = "<b><i>" + result + "</b></i>"; //EMPHASIS DAMNIT!
return result;

} //end euler module