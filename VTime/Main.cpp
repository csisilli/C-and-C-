#include <iostream>
#include "VTime.h"
using namespace std;

int main() {
	VTime a(1,0,11);
	VTime c;  
	c.PresentTime();
	cout << c;
	int x;
	x = a - c;
	if (x == 0) {
		cout << "Error the time is Negative" << endl;
	}
	else {
		cout << "The time is not midnight" << endl;
	}
	return 0;
}