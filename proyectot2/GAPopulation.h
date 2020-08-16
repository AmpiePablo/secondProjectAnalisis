#ifndef GAPOPULATION_H
#define GAPOPULATION_H

#include "RoadLimit.h"
#include "Individuo.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class GAPopulation {
private:
	vector<Individuo> population;
	RoadLimit *road;
	int MAXGRADE;
public:
	GAPopulation() {
		srand(time(NULL));
		road = new RoadLimit();
		road->readImage();
		MAXGRADE = 180;
	}

	void generatePopulation() {
		int index = 0;
		int ejeX, ejeY;
		while (index < 25) {
			ejeX = rand() % 1800;
			ejeY = rand() % 904;
			if (road->verifyArea(ejeX,ejeY)) {
				Individuo *temp = Individuo(ejeX, ejeY);
				population.push_back(temp);
				index++;
			}
		}
	}

	double fitness(Individuo pInviduo) {

	}
	//generar dos puntos apartir de un radio y una función trigonometrica
	void moveIndiviuo(double radius, double grade, bool backwards, int MAXGRADE,Individuo* pIndi) {
		int x = radius * cos(grade);
		int y = radius * sin(grade);
		pIndi->setEjeX(x);
		pIndi->setEjeY(y);
		if (backwards) {
			grade--;
			if (grade == 0)
				backwards = false;
		}
		else {
			grade++;
			if (grade >= MAXGRADE)
				backwards = true;
		}
		//Aqui debìa calcular los rangos
	}
};
#endif // !GAPOPULATION_H

