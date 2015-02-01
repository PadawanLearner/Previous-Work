
//insertion
void insertionSort(int myArray[], int length) {

	int i, j, temp;

	//go through the unsorted array:
	for (i = 1; i < length; i++) {
		
		//the current spot is at j:
		j = i;
		
		//is the previous element greater than the current element being compared: 
		while (j > 0 && myArray[j - 1] > myArray[j]) {
			

			//then we need to swap them
			temp = myArray[j];
			
			myArray[j] = myArray[j - 1];
			
			myArray[j - 1] = temp;
			

			j--; //decrement here so we can continue to test this "sub section" of the array to make sure the element will be inserted into the correct place
			

		}
	}
}


