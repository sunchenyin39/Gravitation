#pragma once
#include<iostream>
#include"Vector.h"
#include"Vector4D.h"
#include"Star_Sun.h"
#include<graphics.h>
class Star{
private:
	Vector4D* zero;//Zero derivative of space coordinates
	Vector4D* first;//one derivative of space coordinates
	Vector4D* second;//Ztwo derivative of space coordinates
	double radius;//star radius
	double mass;//star mass 
	COLORREF color;//star color
	int it_front; //The index of the most recent data
	int draw_number;
public:
	Star();
	Star(const Star& s_value);
	~Star();
	Vector4D* get_zero(void);
	Vector4D* get_first(void);
	Vector4D* get_second(void);
	double get_radius(void);
	double get_mass(void);
	COLORREF get_color(void);
	void set_zero_init(const Vector4D& zero_value);
	void set_first_init(const Vector4D& first_value);
	void set_radius(double radius_value);
	void set_mass(double mass_value);
	void set_color(COLORREF color_value);
	friend std::ostream& operator<<(std::ostream& os, const Star& s_value);
	void draw(Vector s_value);//draw function
	void wipe(Vector s_value);//wipe function
	void gravitation(Star_Sun& s_value);//Calculate the effect of gravity
};

																								