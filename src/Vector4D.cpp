#include "Vector4D.h"
#include<iostream>
Vector4D::Vector4D() {
	t = 0;
	r = 0;
	theta = 0;
	fai = 0;
};
Vector4D::Vector4D(double t_value, double r_value, double theta_value, double fai_value) {
	t = t_value;
	r = r_value;
	theta = theta_value;
	fai = fai_value;
};
Vector4D::Vector4D(const Vector4D& v_value) {
	t = v_value.t;
	r = v_value.r;
	theta= v_value.theta;
	fai = v_value.fai;
};
double Vector4D::get_t(void) { return t; };
double Vector4D::get_r(void) { return r; };
double Vector4D::get_theta(void) { return theta; };
double Vector4D::get_fai(void) { return fai; };
void Vector4D::set_t(double t_value) { t = t_value; };
void Vector4D::set_r(double r_value) { r = r_value; };
void Vector4D::set_theta(double theta_value) { theta = theta_value; };
void Vector4D::set_fai(double fai_value) { fai = fai_value; };
void Vector4D::set(double t_value, double r_value, double theta_value, double fai_value) {
	t = t_value;
	r = r_value;
	theta = theta_value;
	fai = fai_value;
};
Vector4D operator+(const Vector4D& v1_value, const Vector4D& v2_value) {
	Vector4D v_result;
	v_result.t = v1_value.t + v2_value.t;
	v_result.r = v1_value.r + v2_value.r;
	v_result.theta = v1_value.theta + v2_value.theta;
	v_result.fai = v1_value.fai + v2_value.fai;
	return v_result;
};
Vector4D operator-(const Vector4D& v1_value, const Vector4D& v2_value) {
	Vector4D v_result;
	v_result.t = v1_value.t - v2_value.t;
	v_result.r = v1_value.r - v2_value.r;
	v_result.theta = v1_value.theta - v2_value.theta;
	v_result.fai = v1_value.fai - v2_value.fai;
	return v_result;
};
Vector4D& Vector4D::operator=(const Vector4D& v_value) {
	t = v_value.t;
	r = v_value.r;
	theta = v_value.theta;
	fai = v_value.fai;
	return *this;
};
std::ostream& operator<<(std::ostream& os, const Vector4D& v_value) {
	os << "(" << v_value.t << "," << v_value.r << "," << v_value.theta << "," << v_value.fai << ")";
	return os;
};