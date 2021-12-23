#pragma once
#include<iostream>
class Vector{
private:
	double x;
	double y;
public:
	Vector();
	Vector(double x_value, double y_value);
	Vector(const Vector& v_value);
	double get_x();
	double get_y();
	void set_x(double x_value);
	void set_y(double y_value);
	friend Vector operator+(const Vector& v1_value,const Vector& v2_value);
	friend Vector operator-(const Vector& v1_value, const Vector& v2_value);
	Vector& operator=(const Vector& v_value);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v_value);
	double get_length(void);
};

