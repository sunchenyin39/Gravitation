#include"number.h"
#include "Star.h"
#include"Vector.h"
#include"Vector4D.h"
#include<graphics.h>
#include<math.h>
int mod(int a, int b) {//mod function
	if (a >= 0)
		return a % b;
	else
		mod(a + b, b);
}
Star::Star() {
	zero = new Vector4D[time_number];
	first = new Vector4D[time_number];
	second = new Vector4D[time_number];
	radius = 1.0;
	mass = 0.1;
	color = 0xFFFFFF;//default color: white
	it_front = 0;
	draw_number = 0;
};
Star::Star(const Star& s_value) {
	zero = new Vector4D[time_number];
	first = new Vector4D[time_number];
	second = new Vector4D[time_number];
	for (int i = 0; i < time_number; i++) {
		zero[i] = s_value.zero[i];
		first[i] = s_value.first[i];
		second[i] = s_value.second[i];
	}
	radius = s_value.radius;
	mass = s_value.mass;
	color = s_value.color;
	it_front = s_value.it_front;
	draw_number = s_value.draw_number;
};
Star::~Star() {
	delete[] zero;
	delete[] first;
	delete[] second;
};
Vector4D* Star::get_zero(void) { return zero; };
Vector4D* Star::get_first(void) { return first; };
Vector4D* Star::get_second(void) { return second; };
double Star::get_radius(void) { return radius; };
double Star::get_mass(void) { return mass; };
COLORREF Star::get_color(void) { return color; };
void Star::set_zero_init(const Vector4D& zero_value) { 
	for (int i = 0; i < time_number; i++) {
		zero[i] = zero_value;
	}
	it_front = 0;
	draw_number = 0;
};
void Star::set_first_init(const Vector4D& first_value) { first[it_front] = first_value; };
void Star::set_radius(double radius_value) { radius = radius_value; };
void Star::set_mass(double mass_value) { mass = mass_value; };
void Star::set_color(COLORREF color_value) { color = color_value; };
std::ostream& operator<<(std::ostream& os, const Star& s_value) {
	os << "0 order:" << s_value.zero[s_value.it_front] << std::endl;
	os << "1 order:" << s_value.first[s_value.it_front] << std::endl;
	os << "2 order:" << s_value.second[(s_value.it_front+1)% time_number] << std::endl;
	os << "radius:" << s_value.radius << std::endl;
	os << "mass:" << s_value.mass << std::endl;
	os << "color:" << s_value.color << std::endl;
	return os;
};
void Star::draw(Vector s_value) {//draw function(we assume that the movement dimension of stars is two)
	draw_number++;
	setcolor(color);
	setfillcolor(color);
	fillcircle(s_value.get_x() + zero[it_front].get_r() * cos(zero[it_front].get_fai()), s_value.get_y() + zero[it_front].get_r() * sin(zero[it_front].get_fai()),radius);
};
void Star::wipe(Vector s_value) {//wipe function
	if(draw_number>=time_number-1){
		setcolor(0x000000);//blackboard coler is black
		setfillcolor(0x000000);
		fillcircle(s_value.get_x() + zero[mod(it_front - 1, time_number)].get_r() * cos(zero[mod(it_front - 1, time_number)].get_fai()), s_value.get_y() + zero[mod(it_front - 1, time_number)].get_r() * sin(zero[mod(it_front - 1, time_number)].get_fai()), radius);
		//star trailing radius
	}
};
void Star::gravitation(Star_Sun& s) {//calculating the function of the Gravitation
	second[it_front].set_t(-G * s.get_mass() / (pow(C_v * zero[it_front].get_r(), 2)) * pow(1 - 2 * G * s.get_mass() / zero[it_front].get_r() / pow(C_v, 2), -1) * first[it_front].get_t() * first[it_front].get_r() * 2);
	second[it_front].set_r(-G * s.get_mass() / (pow(zero[it_front].get_r(), 2)) * pow(1 - 2 * G * s.get_mass() / zero[it_front].get_r() / pow(C_v, 2), 1) * first[it_front].get_t() * first[it_front].get_t() + G * s.get_mass() / (pow(C_v * zero[it_front].get_r(), 2)) * pow(1 - 2 * G * s.get_mass() / zero[it_front].get_r() / pow(C_v, 2), -1) * first[it_front].get_r() * first[it_front].get_r() + zero[it_front].get_r() *  pow(1 - 2 * G * s.get_mass() / zero[it_front].get_r() / pow(C_v, 2), 1) * first[it_front].get_theta() * first[it_front].get_theta() + zero[it_front].get_r() * pow(1 - 2 * G * s.get_mass() / zero[it_front].get_r() / pow(C_v, 2), 1) * first[it_front].get_fai() * first[it_front].get_fai());
	second[it_front].set_theta(0);
	second[it_front].set_fai(-pow(zero[it_front].get_r(), -1) * first[it_front].get_r() * first[it_front].get_fai() * 2);

	zero[mod(it_front-1,time_number)].set_t(zero[it_front].get_t() + first[it_front].get_t() * timescale * 0.001);
	zero[mod(it_front - 1, time_number)].set_r(zero[it_front].get_r() + first[it_front].get_r() * timescale * 0.001);
	zero[mod(it_front - 1, time_number)].set_theta(PI/2);
	zero[mod(it_front - 1, time_number)].set_fai(zero[it_front].get_fai() + first[it_front].get_fai() * timescale * 0.001);

	first[mod(it_front - 1, time_number)].set_t(first[it_front].get_t() + second[it_front].get_t() * timescale * 0.001);
	first[mod(it_front - 1, time_number)].set_r(first[it_front].get_r() + second[it_front].get_r() * timescale * 0.001);
	first[mod(it_front - 1, time_number)].set_theta(0);
	first[mod(it_front - 1, time_number)].set_fai(first[it_front].get_fai() + second[it_front].get_fai() * timescale * 0.001);
	
	it_front = mod(it_front - 1, time_number);
};

