#pragma once
#include<iostream>
class Vector4D{
private:
	double t;
	double r;
	double theta;
	double fai;
public:
	Vector4D();
	Vector4D(double t_value, double r_value, double theta_value, double fai_value);
	Vector4D(const Vector4D& v_value);
	double get_t(void);
	double get_r(void);
	double get_theta(void);
	double get_fai(void);
	void set_t(double t_value);
	void set_r(double r_value);
	void set_theta(double theta_value);
	void set_fai(double fai_value);
	void set(double t_value, double r_value, double theta_value, double fai_value);
	friend Vector4D operator+(const Vector4D& v1_value, const Vector4D& v2_value);
	friend Vector4D operator-(const Vector4D& v1_value, const Vector4D& v2_value);
	Vector4D& operator=(const Vector4D& v_value);
	friend std::ostream& operator<<(std::ostream& os, const Vector4D& v_value);
};

