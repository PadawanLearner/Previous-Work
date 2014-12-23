
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int digits){
	string myStr = to_string(digits);
	bool flag = false;

	if (!(myStr.length() % 2 == 0)) //is odd? then cannot be palindromic
		return false;
	else{							//test all even cases
		int i = 0;
		
		while (!flag && i < (myStr.length() / 2)){
			if (!(myStr[i] == myStr[(myStr.length()-1-i)])) //test for palindrome
				flag = true; 
			i++;
		}
	}
	if (flag == false)
		return true;
	else
		return false;
};


int main()
{
	int largest = 0;

	for (int i = 100; i < 1000; i++){
		for (int j = 100; j < 1000; j++){
			if (isPalindrome(i*j)){
				if (i*j > largest){
					largest = i*j;
					cout << endl << largest << endl;
				}
			}
		}
	}


	system("PAUSE");
	return 0;
}
