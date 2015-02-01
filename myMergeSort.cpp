
//mergeSort
int* mergeSort(int myArray[], int arraySize){

	if (arraySize > 1){
		
		//split up the lower half
		int* tempLower = new int[arraySize / 2];
		
		partitionArray(tempLower, myArray, 0, arraySize / 2 - 1);



		//split up the upper half
		int* tempUpper = new int[arraySize - (arraySize / 2)];
		
		partitionArray(tempUpper, myArray, (arraySize / 2), arraySize - 1);


		return merge(mergeSort(tempLower, (arraySize / 2)), (arraySize / 2), mergeSort(tempUpper, (arraySize - (arraySize / 2))), (arraySize - (arraySize / 2)));
	}
	else
		return myArray;


}

int* merge(int x[], int xSize, int y[], int ySize){

	if (xSize == 0){
		return y;
		
	}
	if (ySize == 0){
		return x;
		
	}

	//this variable will hold the the value of the temporary merge, i.e. the recursion
	int mergeResultSize = xSize + ySize - 1;
	
	int* mergeResult = new int[mergeResultSize];
	


	if (x[0] <= y[0]){
		

		int* tempX = new int[xSize - 1];
		
		tempX = partitionArray(tempX, x, 1, xSize - 1); //x[2....k]
		

		mergeResult = merge(tempX, xSize - 1, y, ySize); 	//merge(x[2..k],y[1..l]

		int* singletonX = new int[1];
		
		singletonX[0] = x[0];
		


		int* finalResult = new int[xSize + ySize];
		
		//return(concatenateArrays(finalResult, singletonX, 1, mergeResult, mergeResultSize)); //x[1] concatenate merge(x[2..k]; y[1..l])
		(concatenateArrays(finalResult, singletonX, 1, mergeResult, mergeResultSize));
		delete[] mergeResult;
		delete[] tempX;
		delete[] singletonX;
		return finalResult;
	}

	else{
		int* tempY = new int[ySize - 1];
		
		tempY = partitionArray(tempY, y, 1, ySize - 1); //y[2....k]
		

		mergeResult = merge(x, xSize, tempY, ySize - 1); //merge(x[1..k],y[2..l]


		int* singletonY = new int[1];
		
		singletonY[0] = y[0];
		

		int* finalResult = new int[xSize + ySize];
		
		//return(concatenateArrays(finalResult, singletonY, 1, mergeResult, mergeResultSize)); //y[1] concatenate merge(x[1..k]; y[2..l])
		(concatenateArrays(finalResult, singletonY, 1, mergeResult, mergeResultSize));
		delete[] mergeResult;
		delete[] tempY;
		delete[] singletonY;
		return finalResult;
	}

}


//needed to break up arrays before sending them through mergesort break down/build-up
int* partitionArray(int newArray[], int copiedArray[], int start, int end){

	int range = end - start;
	

	for (int i = 0; i <= range; i++){
		
		newArray[i] = copiedArray[start];
		
		start++;
		
	}
	return newArray;
}


//concatenates x with y, i.e. x goes first
int* concatenateArrays(int newArray[], int x[], int xSize, int y[], int ySize){

	for (int i = 0; i < xSize; i++){
		newArray[i] = x[i];
		
	}
	for (int i = 0; i < ySize; i++){
		newArray[i + xSize] = y[i];
		
	}

	return newArray;
}
