#pragma once
#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include <vector>
using namespace std;


class Individuo {
private:
	double ejeX;
	double ejeY;
	double visibility;
	double fit;
	int distribution[4][3];


public:
	Individuo(double pX, double pY) {
		ejeX = pX;
		ejeY = pY;
		visibility = 180;
		fit = 0;
		//rarngos o comprtamientos de indivius, la ultima poscion de cada arreglo de la matriz
		//es la probabilidad de cada rango, la idea subir proba al rango, y y ver en este individuo, cual
		//rango es el que mas le favorece para girar
		distribution = { {0,45,0},{45,90,0},{90,135,0},{135,180,0} };
	}

	int[][] getDistribution() {
		return distribution;
	}

	double getEjeX() {
		return ejeX;
	}
	double getEjeY() {
		return ejeY;
	}
	double getFit() {
		return fit;
	}
	double getVisibility() {
		return visibility;
	}

	void setEjeX(double pX) {
		ejeX=pX;
	}
	void setEjeY(double pY) {
		 ejeY=pY;
	}



};
#endif //  INDIVIDUO_H
