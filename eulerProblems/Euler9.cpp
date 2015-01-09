/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/


#include <iostream>

using namespace std;

int main(){
	
	/*
	I spent about 30 minutes thinking about an elegant way to solve this problem and could not see it, so I eventually resorted to
	a robust solution.  I basically thought about the limits of what a, b, and c could be such that they retain the definition of a<b<c. 
	The rest is simply looping through and checking for success.  Complexity here should be  (2n/3) * (n/2) * (n/3) .....I think 
	*/

	for (int c = 335; c < 997; c++){
		for (int b = 2; b < 499; b++){
			for (int a = 1; a < 331; a++){

				if (b < c  && a < b && ((c + b + a) == 1000)){
					if ((a*a + b*b) == (c*c))
						cout << endl << a*b*c << endl;
				}
			}
		}
	}
	system("PAUSE");
	return 0;
}