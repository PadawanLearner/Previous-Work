// quick
void quickSort(int myArray[], int left, int right) {
	int i = left, j = right;
	countOperations++;
	countOperations++;
	int temp;
	int pivot = myArray[(left + right) / 2];
	countOperations++;


	// partition 
	//start at both ends:
	while (i <= j) {
		countOperations++;
		//move from the left, encounter and bypass all values less than the pivot:
		while (myArray[i] < pivot){
			i++;
			countOperations++;
		}
		//move from the right, encounter and bypass all the values greater than the pivot
		while (myArray[j] > pivot){

			j--;
			countOperations++;
		}
		//now i and j have stopped at an index that needs to be moved to the other side of the pivot
		if (i <= j) {
			countOperations++;
			temp = myArray[i];
			countOperations++;
			//move the items to their proper side of the pivot
			myArray[i] = myArray[j];
			countOperations++;
			myArray[j] = temp;
			countOperations++;
			//move the pivot trackers in closer for the next iteration
			i++;
			countOperations++;
			j--;
			countOperations++;
		}
	};


	// quicksort itself, recursion is actually the easy part in this sort:
	if (left < j){
		quickSort(myArray, left, j);
		countOperations++;
	}
	if (i < right){
		quickSort(myArray, i, right);
		countOperations++;
	}
}
