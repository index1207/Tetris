#include <iostream>
#include <format>

#include <Windows.h>

#include "basic.h"

using namespace std;

void ttrs::Point2D::gotoxy(short x, short y) {
	COORD _pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
}

ttrs::console::console(Point2D _size) {
	this->size.x = _size.x;
	this->size.y = _size.y;
	system(format("mode con cols={} lines={}", size.x, size.y).c_str());
}

ttrs::console::console(Point2D _size, const char* title) {
	this->size.x = _size.x;
	this->size.y = _size.y;

	system(format("mode con cols={} lines={}", size.x, size.y).c_str());
	SetConsoleTitle(title);
}

ttrs::console::console(consoleInfo& con) {
	this->size.x = con.x;
	this->size.y = con.y;

	this->title = title;

	system(format("mode con cols={} lines={}", size.x, size.y).c_str());
	SetConsoleTitle(title.c_str());

	Point2D::gotoxy(con.pos.x, con.pos.x);
}

void ttrs::console::setTitle(const char* title) {
	this->title = title;

	SetConsoleTitle(title);
}

void ttrs::console::setSize(short x, short y) {
	size.x = x;
	size.y = y;
	system(format("mode con cols={} lines={}", size.x, size.y).c_str());
}

void ttrs::console::setSize(Point2D p) {
	size.x = p.x;
	size.y = p.y;
	system(format("mode con cols={} lines={}", size.x, size.y).c_str());
}