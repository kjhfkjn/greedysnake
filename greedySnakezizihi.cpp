
#include <graphics.h>
#include <conio.h>
#include<iostream>
#include"snake.h"
#include"food.h"
using namespace std;

int main()
{
	// 创建绘图窗口
	initgraph(640, 480);
	snake snake1;
	snake1.start();
	food food1(snake1.width);
	food1.start();
	int key;
	while (snake1.getss()) {
		if (_kbhit()) {
			key = _getch();
			snake1.keyboard(key);
		}
		snake1.loop();
		if (snake1.getfood(food1.getxy())) {
			food1.restart();
		}
	}


	
	return 0;
}