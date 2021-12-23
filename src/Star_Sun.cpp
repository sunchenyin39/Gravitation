#include"number.h"
#include "Star_Sun.h"
#include<graphics.h>
#include"Vector"
#include<iostream>
Star_Sun::Star_Sun() {
	position.set_x(1600 / 2);
	position.set_y(1000 / 2);
	radius = 25.0;
	mass = 1.0;
	color = 0xFFFFFF;
};
Star_Sun::Star_Sun(const Star_Sun& s_value) {
	position = s_value.position;
	radius = s_value.radius;
	mass = s_value.mass;
	color = s_value.color;
};
Vector Star_Sun::get_position(void) { return position; };
double Star_Sun::get_radius(void) { return radius; };
double Star_Sun::get_mass(void) { return mass; };
COLORREF Star_Sun::get_color(void) { return color; };

void Star_Sun::set_position(const Vector& position_value) { position = position_value; };
void Star_Sun::set_radius(double radius_value) { radius = radius_value; };
void Star_Sun::set_mass(double mass_value) { mass = mass_value; };
void Star_Sun::set_color(COLORREF color_value) { color = color_value; };

std::ostream& operator<<(std::ostream& os, const Star_Sun& s_value) {
	std::cout << s_value.position << std::endl;
	std::cout << s_value.radius << std::endl;
	std::cout << s_value.mass<< std::endl;
	std::cout << s_value.color << std::endl;
	return os;
};
void Star_Sun::draw(void) {//draw function
	setcolor(color);
	setfillcolor(color);
	fillcircle(position.get_x(), position.get_y(), radius);
};
void Star_Sun::wipe(void) {//wipe function
	setcolor(0x000000);
	setfillcolor(0x000000);//backboard coloer is black
	fillcircle(position.get_x(), position.get_y(), radius);
};