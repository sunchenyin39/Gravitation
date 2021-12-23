#pragma once
#include"Vector.h"
#include<graphics.h>
#include<iostream>
class Star_Sun
{private:
	Vector position;
	double radius;//star radius
	double mass;//star mass
	COLORREF color;//star color
public:
	Star_Sun();
	Star_Sun(const Star_Sun& s_value);
	Vector get_position(void);
	double get_radius(void);
	double get_mass(void);
	COLORREF get_color(void);
	void set_position(const Vector& position_value);
	void set_radius(double radius_value);
	void set_mass(double mass_value);
	void set_color(COLORREF color_value);
	friend std::ostream& operator<<(std::ostream& os, const Star_Sun& s_value);
	void draw(void);//draw function
	void wipe(void);//wipe function
};

