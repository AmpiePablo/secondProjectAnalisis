#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "RoadLimit.h"
using namespace std;

int main() {
	RoadLimit *road = new RoadLimit();
	road->readImage();
	if (road->verifyArea(150, 600)) {
		cout << "entro\n";
	}
	else {
		cout << "No entro\n";
	}
	return 0;
}