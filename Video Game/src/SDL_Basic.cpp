//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "Screen.h"
using namespace std;
using namespace sdlGraphics;

int main() {

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	while (true) {
		//update particles
		//Draw particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128); //we multiply by 0.001 to smooth the changes
		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0002))
				* 128); //we multiply by 0.001 to smooth the changes
		unsigned char blue =
				(unsigned char) ((1 + sin(elapsed * 0.0003)) * 128); //we multiply by 0.001 to smooth the changes

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		//Draw the screen
		screen.update();

		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
