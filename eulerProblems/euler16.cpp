/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <vector>

using namespace std;

//Returns a vector of digits representing the parameter passed multiplied by 2 in reverse order
//998 is represented as vec[0]=8, vec[1]=9, vec[2]=9 
vector <int> multiplyByTwo(vector <int> num){
	vector <int> result;
	int carry = 0;

	for (int i = 0; i < num.size(); i++){
		result.push_back(((num[i] * 2) + carry) % 10);
		if ((num[i] * 2) > 9)
			carry = 1;
		else
			carry = 0;
	}
	//Avoid leading zeros
	if (carry != 0)
		result.push_back(carry);

	return result;
}



int main(){

	vector <int> myVec = {1};

	for (int i = 0; i < 1000; i++)
		myVec = multiplyByTwo(myVec);
	
	int sum = 0;
	for (int i = 0; i < myVec.size(); i++){
		sum = sum + myVec[i];
	}

	cout << sum;
	cout << endl;
	system("PAUSE");
	return 0;
}