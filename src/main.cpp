#include"number.h"
#include <graphics.h>
#include<iostream>
#include"Vector.h"
#include"Star.h"
#include"Star_Sun.h"
#include"Vector4D.h"
using namespace std;
int main(void) {
	Star_Sun Sun;
	Star earth;//earth
	//set the init parameter of the earth
	Vector4D earth_zero;
	Vector4D earth_first;
	earth_zero.set(0, 300, PI / 2, 0);
	earth_first.set(1, 0, 0, 1);
	earth.set_zero_init(earth_zero);
	earth.set_first_init(earth_first);
	initgraph(Width, Height);//generate window
	Sun.draw();
	BeginBatchDraw();
	int i = 1;
	while (1) {
		earth.wipe(Sun.get_position());
		earth.gravitation(Sun);
		earth.draw(Sun.get_position());
		i++;
		if (i == 100) {
			i = 1;
			FlushBatchDraw();
		}

	}
	EndBatchDraw();
	system("pause");
	closegraph();//close window
	return 0;
}

