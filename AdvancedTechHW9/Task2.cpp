#include <iostream>
#include <cmath>


using namespace std;


enum Colour {

	RED,
	BLUE,
	GREEN
};


class GeometricShape {

protected:

	double cy, cx;

	Colour colour;


public:

	const double pi = atan(1), sq3 = sqrt(3);

	/*GeometricShape(): cy(0), cx(0), colour(Colour::BLUE) {
	
	
	}*/


	GeometricShape(double cy, double cx, Colour colour) {

		this->cy = cy;
		this->cx = cx;
		this->colour = colour;

	}

	virtual double getArea() const = 0;

};


class Rectanle : public GeometricShape {

private:
	double width, height;

public:

	Rectanle(double cy, double cx, Colour colour, double width, double height) : GeometricShape(cy, cx, colour) {

		this->width = width;
		this->height = height;

	}

	double getArea() const override {

		return width * height;

	}

	Rectanle getRect() {

		return *this;

	}

};


class Triangle: public GeometricShape {

private:

	double edge;

public:

	Triangle(double cy, double cx, Colour colour, double edge): GeometricShape(cy, cx, colour) {
	
		this->edge = edge;
	
	}

	double getArea() const override {

		return sq3 * edge * edge / 4;

	}

	Rectanle getRect() {
	
		return Rectanle(cy, cx, colour, edge, 2 * edge / sq3);
	
	}

};


class Square: public GeometricShape {

private:

	double edge;

public:

	Square(double cy, double cx, Colour colour, double edge) : GeometricShape(cy, cx, colour) {

		this->edge = edge;

	}

	double getArea() const override {

		return edge * edge;

	}

	Square getRect() {

		return *this;

	}

};


class Circle: public GeometricShape{

private:
	double radius;

public:

	Circle(double cy, double cx, Colour colour, double radius) : GeometricShape(cy, cx, colour) {

		this->radius = radius;

	}

	double getArea() const override {

		return pi * radius * radius;

	}

	Rectanle getRect() {

		return Rectanle(cy, cx, colour, 2 * radius, 2 * radius);

	}

};


void task2() {




}
