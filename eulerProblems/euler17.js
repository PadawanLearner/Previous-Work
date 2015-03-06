var uniqueNums =
["","one","two","three","four","five","six","seven", "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" ];

var uniqueTens = 
 ["","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"];
 
var hundred = "hundred";
      
function numberToWord(num){
     
 if( (num > 0) &&  (num < 20)){
     return uniqueNums[num];
}
 else if((num >= 20) && (num < 100)){
     return uniqueTens[Math.floor((num/10))]+uniqueNums[(num%10)];
}
 else if((num >= 100) && (num < 1000)){
    var temp = (uniqueNums[Math.floor(num/100)])+"hundred";
    
    if(num%100){
     temp = temp + "and"+(uniqueTens[Math.floor(((num%100)/10))]);
                                              
        if ((num%100) < 20){
            temp = temp +  uniqueNums[(num%100)];
        }
        else{
             temp = temp + uniqueNums[num%10];
         }
     } 
        
     return temp;                                                  
}
 else{
 return "onethousand";
}
    
 
}
var answer=0;
for (var i=1; i < 1001; i++){
    //alert(numToWord(i));
    answer = answer + numberToWord(i).length;
}

//alert(numToWord(230));
alert(answer);