// MyInitials.cpp
// Edited by: (PUT YOUR NAME HERE, and the DATE)
//
// A program that draws my initials on the screen
// Press any key to quit.

#include "graphics.h"
#include "cmath"
#include "iostream"
#include "math.h"
#include "thread"
using namespace std;

const double pi = 3.14159265358979323846;

double degToRad(double deg) {
	return deg * pi / 180.0;
}

void animateO() {
	int x1 = 0, x2 = 0, rememX;
	while (1) {
		for (int i = 10; i <= 350; i += 10) {
			x1 = 380, x2 = 620;
			while (x1 != x2) {
				//cout << x1 << ", " << y1 << "   ";
				if (getpixel(x1, i + 100) == WHITE) {
					while (getpixel(x1, i + 100) == WHITE) {
						x1++;
					}
					rememX = x1;
					while (getpixel(x1, i + 100) != WHITE) {
						x1++;
					}
					setlinestyle(SOLID_LINE, 0, 1);
					setcolor(RED);
					line(rememX, i + 100, x1 - 1, i + 100);
					while (getpixel(x1, i + 100) == WHITE) {
						x1++;
					}
				}
				else {
					x1++;
				}
			}
			delay(15);
		}
		for (int i = 10; i <= 350; i += 10) {
			x1 = 380, x2 = 620;
			while (x1 != x2) {
				//cout << x1 << ", " << y1 << "   ";
				if (getpixel(x1, i + 100) == RED) {
					putpixel(x1, i + 100, BLACK);
				}
				x1++;
			}
			delay(15);
		}
	}
}

void drawRectangle(int x, int y, double deg, int length, int width) { // Coordinate of top right rectangle point, degree of rotation, length (downwards), width (to the right)
	setlinestyle(SOLID_LINE, 0, width);
	line(x, y, int(sin(deg) * length) + x, int(cos(deg) * length) + y);
	//cout << sin(deg) * length + x << ", " << cos(deg) * length + y << '\n';
}

int shiftLR = -100, radius = 90;
void writeR() {
	setcolor(LIGHTCYAN); //outline color
	setfillstyle(SOLID_FILL, LIGHTCYAN); //inside color
	bar(220 + shiftLR, 100, 240 + shiftLR, 450);
	bar(250 + shiftLR, 100, 280 + shiftLR, 450);
	setcolor(LIGHTGRAY); //outline color
	setfillstyle(BKSLASH_FILL, YELLOW); //inside color
	pieslice(290 + shiftLR, 100 + radius, 270, 90, radius);
	arc(295 + shiftLR, 100 + radius, 270, 90, radius);
	arc(300 + shiftLR, 100 + radius, 270, 90, radius);
	arc(305 + shiftLR, 100 + radius, 270, 90, radius);
	arc(310 + shiftLR, 100 + radius, 270, 90, radius);
	arc(315 + shiftLR, 100 + radius, 270, 90, radius);
	arc(320 + shiftLR, 100 + radius, 270, 90, radius);
	
	drawRectangle(348 + shiftLR, 295, degToRad(19.0), 162, 40);
}

void writeO() {
	int xrad = 120, yrad = 175, width = 48;
	setcolor(WHITE); //outline color
	ellipse(500, 275, 0, 360, xrad, yrad);
	//setfillstyle(BKSLASH_FILL, DARKGRAY);
	//fillellipse(500, 275, xrad, yrad);
	setcolor(WHITE);
	ellipse(500, 275, 0, 360, xrad - width, yrad - width);
	setfillstyle(EMPTY_FILL, BLACK);
	fillellipse(500, 275, xrad - width, yrad - width);
}

int pies = 80;
bool ripple = 0, rev = 0;
void animateR() {
	while (1) {
		while (pies > 50){
			setfillstyle(EMPTY_FILL, BLACK);
			setlinestyle(SOLID_LINE, 0, 1);
			setcolor(WHITE);
			pieslice(290 + shiftLR, 100 + radius, 270, 90, radius);
			setfillstyle(SOLID_FILL, BLUE);
			setcolor(BLUE);
			pieslice(235 - (radius - pies) / 2, 100 + radius, 270, 90, radius - pies);
			pies -= 2;
			delay(90);
		};
		do {
			setfillstyle(EMPTY_FILL, BLACK);
			setlinestyle(SOLID_LINE, 0, 1);
			setcolor(WHITE);
			pieslice(290 + shiftLR, 100 + radius, 270, 90, radius);
			setfillstyle(SOLID_FILL, BLUE);
			setcolor(BLUE);
			pieslice(235 - (radius - pies) / 2, 100 + radius, 270, 90, radius - pies);
			pies -= 5;
			delay(25);
		} while (pies > 0);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLUE);
		pieslice(235 - (radius - pies) / 2, 100 + radius, 270, 90, radius - pies);
		ripple = 1;
		while (pies <= 80) {
			setfillstyle(EMPTY_FILL, BLACK);
			setlinestyle(SOLID_LINE, 0, 1);
			setcolor(WHITE);
			pieslice(290 + shiftLR, 100 + radius, 270, 90, radius);
			setfillstyle(SOLID_FILL, BLUE);
			setcolor(BLUE);
			pieslice(235 - (radius - pies) / 2, 100 + radius, 270, 90, radius - pies);
			pies += 5;
			delay(30);
		}
	}
}

void animateR2() {
	int arcX = 0;
	while (1) {
		if (ripple) {
			arcX = 0;
			do {
				setlinestyle(SOLID_LINE, 0, 1);
				setcolor(BLUE);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 1) % 6;
				setcolor(BLUE);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 1) % 6;
				setcolor(LIGHTGRAY);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 1) % 6;
				setcolor(LIGHTGRAY);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 1) % 6;
				setcolor(LIGHTGRAY);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 1) % 6;
				setcolor(LIGHTGRAY);
				arc(295 + arcX * 5 + shiftLR, 100 + radius, 270, 90, radius);
				arcX = (arcX + 2) % 6;
				delay(100);
			} while (arcX != 5);
			setcolor(LIGHTGRAY);
			arc(320 + shiftLR, 100 + radius, 270, 90, radius);
			setcolor(LIGHTGRAY);
			arc(315 + shiftLR, 100 + radius, 270, 90, radius);
			ripple = 0;
		}
	}
}

void typer() {
	for (int i = 1; i <= 4; i++) {
		setcolor(WHITE);
		bar(70, 75, 80, 475);
		delay(600);
		cleardevice();
		delay(600);
	}
}

void typer2() {
	for (int i = 1; i <= 3; i++) {
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		bar(70 + 270, 75, 80 + 270, 475);
		delay(600);
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(BLACK);
		bar(70 + 270, 75, 80 + 270, 475);
		delay(600);
	}
}

void typer3() {
	for (int i = 1; i <= 3; i++) {
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		bar(70 + 580, 75, 80 + 580, 475);
		delay(600);
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(BLACK);
		bar(70 + 580, 75, 80 + 580, 475);
		delay(600);
	}
}

int main()
{

	// Open a graphics window size 800 pixels wide x 600 pixels high
	initwindow(800, 600);

	// See "Graphics Functions Examples" on Canvas for list 
	// of functions to use

	// Here are two examples. Erase these and make your own
	// It may be helpful to draw it on paper first
	typer();
	writeR();
	thread th2(animateR);
	thread th3(animateR2);
	th2.detach();
	th3.detach();
	typer2();
	setlinestyle(SOLID_LINE, 0, 1);
	writeO();
	thread th1(animateO);
	thread th4(typer3);
	th1.detach();
	th4.join();

	getch(); //Wait for a key. (When main function ends, the window will close)
	closegraph(); // shut down the graphics window
	return 0;
} // end main()




