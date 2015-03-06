<?php
/*
See here for better visual: https://projecteuler.net/problem=18
This is a brute force way to solve the problem, there is a more elegant solution than this one.


By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23



*/



//this recursion traverses down the pyramid based on left or right (0 or 1) directions in from the $directions variable
function pyPath($currentLevel, $array, $index, $directions, $maxLevel){

	if ($currentLevel == $maxLevel){
		return $array[$currentLevel][$index];
	}
	else{
		$sum = $array[$currentLevel][$index] + pyPath($currentLevel+1, $array, $index+$directions[$currentLevel], $directions, $maxLevel);
		return $sum;
	}
}


//Get the data into a 2d array:
$txt_file = file_get_contents('euler18Data.txt');
$rows = explode("\n", $txt_file);
$pyramid = array();
foreach ($rows as $row){
	array_push($pyramid, explode(" ", $row));
}


//this will hold the answer:
$max=0;

//Now come up with all combinations. 0 for left, 1 for right. 2(possible adjacencies) ^ 14 (rows) = 16384 possible combinations
for ($ctr=0; $ctr < 16384; $ctr++){

	//convert one of possibilities to binary, ie left/right  directions
	$traversalDirectionsStr = decbin($ctr);
	//pad to 14 total directions
	if (strlen($traversalDirectionsStr) < 14){
		for ($i=strlen($traversalDirectionsStr); $i<14; $i++){
			$traversalDirectionsStr = $traversalDirectionsStr."0";
		}
	}
	//put into int array format
	$traversalDirections = array();
	for ($i=0; $i<strlen($traversalDirectionsStr); $i++){
		array_push($traversalDirections, $traversalDirectionsStr[$i]); 
	}
	
	//call our recursive traversal function
	$temp = pyPath(0, $pyramid, 0, $traversalDirections, sizeof($pyramid)-1);

	//find the max
	if ($temp > $max)
		$max = $temp;

}



//echo pyPath(0, $pyramid, 0, $tysk, sizeof($pyramid)-1);



echo "<br>".$max;






?>