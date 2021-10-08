#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

class snake {
public:
	int width;
	snake() :length(2), direction('d'),width(14),ss(1) {
		location.push(make_pair(21*width, 17*width));
		location.push(make_pair(22*width, 17*width));
	}
	int start() {
		fillcircle(location.front().first, location.front().second, width / 2);
		fillcircle(location.back().first, location.back().second, width / 2);
		return 0;
	}
	void loop() {
		display();
		Sleep(200);
		run();
		detect();
	}
	void keyboard(int key) {
		switch (key) {
		case 27:
			ss = 0;
			break;
		case 97:
			direction = 'a';
			break;
		case 115:
			direction = 's';
			break;
		case 119:
			direction = 'w';
			break;
		case 100:
			direction = 'd';
			break;
		}
	}
	void run() {
		setfillcolor(WHITE);
		if (!bgetfood) {
			clearcircle(location.front().first, location.front().second, width / 2);
			location.pop();
		}bgetfood = 0;

		switch (direction) {
		case 'w':
			location.push(make_pair(location.back().first, location.back().second-width));
			break;
		case 's':
			location.push(make_pair(location.back().first, location.back().second + width));
			break;
		case 'a':
			location.push(make_pair(location.back().first-width, location.back().second));
			break;
		case 'd':
			location.push(make_pair(location.back().first+width, location.back().second));
			break;
		}
		
	}
	void detect() {
		int x, y;
		x = location.back().first;
		y = location.back().second;
		if (x < 0 || y < 0 || x>640 || y>480)ss = 0;
	}void display() {
		
		fillcircle(location.back().first, location.back().second, width / 2);
	}
	bool getss() {
		return ss;
	}
	int getfood(pair<int,int> food) {
		if (food == location.back()) {
			length++;
			bgetfood = 1;
			return 1;
		}return 0;
	}

private:
	bool bgetfood=0;
	int length=2;
	
	char direction;
	bool ss;
	queue<pair<int, int>> location;
};