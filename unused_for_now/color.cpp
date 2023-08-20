//
// Created by Aurelien Levra on 20/08/2023.
//

#include "color.h"

color::color() {
	_r = 0;
	_g = 0;
	_b = 0;
	_a = 0;
}

color::color(int r, int g, int b, int a) {
	_r = r;
	_g = g;
	_b = b;
	_a = a;
}

color::~color() {
}

int color::getR() const {
	return _r;
}

int color::getG() const {
	return _g;
}

int color::getB() const {
	return _b;
}

int color::getA() const {
	return _a;
}

void color::setR(int r) {
	_r = r;
}

void color::setG(int g) {
	_g = g;
}

void color::setB(int b) {
	_b = b;
}

void color::setA(int a) {
	_a = a;
}


