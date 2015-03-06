/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?


ctr

func (x start, y start)
	if x or y =  -1    ie left/up from the starting point
		return 

	ctr++

	func(x--, y)
	func(x, y--_
	func (x--, y--)





*/

#include <iostream>

using namespace std;

int ctr = 0;

void findPath(int x, int y){
	
	if ((x < 0) || (y < 0))
		return;

	ctr++;
	findPath(x - 1, y);
	findPath(x, y-1);
	findPath(x - 1, y-1);


}


int main(){

	
	
	cout << ctr << endl;
	system("PAUSE");
	return 0;
}