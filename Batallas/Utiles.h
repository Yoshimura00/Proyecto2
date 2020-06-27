#pragma once
#include <iostream>
#include <random>
#include <ctime>

float random_float(float min, float max) {

	return ((float)rand() / RAND_MAX) * (max - min) + min;

}

float aleatorioFloat() {

	srand(time(NULL));
	float aleatorio=0.f;
	aleatorio = random_float(0.85f, 1.00f) ;
	return 0;

}
