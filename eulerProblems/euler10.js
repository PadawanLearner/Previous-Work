
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/


/*

This problem is easy if you know how to detect primes.  Maybe I should have tried a recursive method to make it more interesting, easier solution?

*/

function isPrime(number) {

    //Two base cases here:
    //By definition one IS NOT considered a prime
    if (number === 1) {
        return false;
    }
    //2 is in a fact a prime, but is the sole exception case to our algorithm used below, so we simply test upfront for it 
    if (number === 2) {
        return true;
    }

    //Robust prime test for all primes greater than 2.
    var squareRootOfNumber = Math.ceil(Math.sqrt(number));
    var isPrime = true;
    var i = 2;
    while (i <= squareRootOfNumber && isPrime) {
        if (number % i == 0) {
            isPrime = false;
            return false;
        }
        i++;
    }
    return isPrime;
};

//Tally the primes
var sumOfPrimes = 0;
for (var i = 1; i < 2000000; i++) {
    if (isPrime(i)) {
        sumOfPrimes = sumOfPrimes + i;

    }
}

alert(sumOfPrimes);
