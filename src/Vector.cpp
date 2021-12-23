#include "Vector.h"
#include<iostream>
#include<math.h>
Vector::Vector() {
	x = 0.0, y = 0.0;
};
Vector::Vector(double x_value, double y_value) {
	x = x_value; y = y_value;
};
Vector::Vector(const Vector& v_value) {
	x = v_value.x;
	y = v_value.y;
};
double Vector::get_x() { return x;};
double Vector::get_y() { return y;};
void Vector::set_x(double x_value) { x = x_value;};
void Vector::set_y(double y_value) {y=y_value;};
Vector operator+(const Vector& v1_value, const Vector& v2_value) {
	Vector v_result;
	v_result.x = v1_value.x + v2_value.x;
	v_result.y = v1_value.y + v2_value.y;
	return v_result;
};
Vector operator-(const Vector& v1_value, const Vector& v2_value) {
	Vector v_result;
	v_result.x = v1_value.x - v2_value.x;
	v_result.y = v1_value.y - v2_value.y;
	return v_result;
};
Vector& Vector::operator=(const Vector& v_value) {
	x = v_value.x;
	y = v_value.y;
	return *this;
};
std::ostream& operator<<(std::ostream& os, const Vector& v_value) {
	os << "("<<v_value.x << "," << v_value.y << ")";
	return os;
};
double Vector::get_length(void) {
	return  sqrt(x * x + y * y);
}