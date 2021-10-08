#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;

class food {
public:
	food(int width):width(width) {
		
	};
	void xy() {
		x = 640 / width;
		y = 480 / width;
		srand((unsigned)time(NULL));
		x = rand() % x;
		y = rand() % y;
		x = x * width;
		y = y * width;
	}
	void start() {
		xy();
		fillrectangle(x - width / 2, y - width / 2, x + width / 2, y + width / 2);
	}
	void restart() {
		clearrectangle(x - width / 2, y - width / 2, x + width / 2, y + width / 2);
		xy();
		solidrectangle(x - width / 2, y - width / 2, x + width / 2, y + width / 2);
	}
	pair<int, int> getxy() {
		return make_pair(x, y);
	}
private:
	int width;
	int x, y;
	int ss;
};