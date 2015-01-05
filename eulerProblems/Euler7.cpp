/*
By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number ?
*/


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


bool isPrime(int num){

	int rootOfNum = floor(sqrt(num));

	for (int i = 2; i <= rootOfNum; i++){
		if (num%i == 0)
			return false;
	}

	return true;
};


int main(){
	
	int ctr = 1;
	vector <int> primes;

	while (primes.size() <= 10001){
		if (isPrime(ctr))
			primes.push_back(ctr);

		ctr++;
	}

	cout << endl << primes.back() << endl;
	system("PAUSE");
	return 0;
}