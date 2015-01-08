/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
		
*/

//Global variable.... number in question
var myNum = 600851475143;


//Functions
function max(number1, number2){
    if (number1 > number2){
      return number1;
    }
    else{
      return number2;   
    }
};

function isPrime(number){
		var squareRootOfNumber = Math.ceil(Math.sqrt(number));
           
		var isPrime = true;
		var i = 2;
		while ( i <= squareRootOfNumber && isPrime ){
			if (number%i == 0){
				isPrime = false;
                return false;
			}
            
			i++;
		}
	
	return isPrime;
};



//The hardcoded assignment
var myMax = 0;

for (var i = 2; i <= Math.ceil(Math.sqrt(myNum)); i++){
    
	if(myNum%i == 0){
		var x = myNum / i;
        var y = myNum / x;
        
		if (isPrime(x)){
			myMax = max(myMax, x);
		}
        if (isPrime(y)){
            myMax = max(myMax, y);   
        }
	}
}

alert(myMax);


