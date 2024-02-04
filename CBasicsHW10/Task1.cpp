#include <iostream>
#include "lib.h"


using namespace std;


void task1() {

	float a, b, c;
	std::cout << "a, b, c:";
	std::cin >> a >> b >> c;  // 'c' variable omitted -> 1st err...
	if (a < 0)
	{
		std::cout << "Not a quadratic equation!" << std::endl;
	}
	else if (a > 0) // 'a' has an impact here, not 'b' -> 2nd err...
	{
		float discriminant = b * b - 4 * a * c;  // 'b' and 'c' switched places -> 3rd err...

		// here was: "return 0;", what for? -> 4th err...

		if (discriminant > 0) // not > 1, but > 0 -> 5th err...
		{
			float x1 = (-b + std::sqrt(discriminant)) / (2 * a);  // discriminand instead of discriminant 2 times -> 6th and 7th errs...
			float x2 = (-b - std::sqrt(discriminant)) / (2 * a);  // ',' instead of ';' and '+' instead of '-' -> 8th and 9th err errs...
			
			std::cout << "Roots 1, 2: " << x1 << ", " << x2 << std::endl; // 'x1' instead of 'x2' -> 10th err...
		}
		else if (discriminant == 0)
		{
			float x = -b / (2 * a); // wrong math expression -> 11th err...
			std::cout << "2-fold Root: " << x << std::endl; // wrong print, 'discriminant' instead of 'x' -> 12th err...
		}
		else
		{
			std::cout << "Complex scenario is not supported!" << std::endl;
		}
	}
	else {	
		// (a == 0) // a == 0 case omitted, possible div by zero...

		// linear case (bx + c = 0):
		if (b == 0) {
		
			cout << "X can be any real number..." << endl;

		} else {
			// b != 0:

			float x = -c / b;
			std::cout << "Root: " << x << std::endl;
		}
	}

}





