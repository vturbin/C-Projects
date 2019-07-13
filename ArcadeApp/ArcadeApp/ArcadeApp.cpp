#include <iostream>
#include "Vec2D.h"

using namespace std;

int main() {
	
	Vec2D aVec(3,4);

	cout << -aVec << endl;

	cout << aVec << endl;

	Vec2D resultVec = 3 * aVec;

	cout << resultVec << endl;

	return 0;
}
