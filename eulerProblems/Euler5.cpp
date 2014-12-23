
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;
long long factorial(int n)
{
	long long factorialResult = 1;

	for (int i = 1; i <= n; i++)
	{
		factorialResult = long long (factorialResult*i);
	}

	return factorialResult;
}

int main()
{
	long long factorialNumber;
	long long smallest = factorial(20);
	bool flag=false;
	int numberOfIntegers = 20;

	bool lookForNextInteger = false;
	long long divisibleInteger = 1;

	while (!lookForNextInteger){
		for (int i = 1; i <= numberOfIntegers; i++){
			if (!(divisibleInteger%i == 0))
				lookForNextInteger = true;
		}
		
		if (lookForNextInteger){
			divisibleInteger++;
			lookForNextInteger = false;
		}
		else{
			cout << endl << "I am divisibleInteger: " << divisibleInteger << endl;
			lookForNextInteger = true;
		}
		
	}

	system("PAUSE");
	return 0;
}
