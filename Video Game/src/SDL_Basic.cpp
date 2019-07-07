//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

#include "Screen.h"
using namespace std;
using namespace sdlGraphics;

int main() {

	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	Swarm swarm;

	while (true) {
		//update particles
		//Draw particles
		const int explosionHPos = Screen::SCREEN_WIDTH / 2;
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128); //we multiply by 0.001 to smooth the changes
		unsigned char green =(unsigned char) ((1 + sin(elapsed * 0.0002)) * 128); //we multiply by 0.002 to smooth the changes
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128); //we multiply by 0.003 to smooth the changes

		const Particle* const pParticles = swarm.getParticles();
		screen.clear();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i]; //getting the individual particles

			int x = (particle.m_x + 1) * explosionHPos;
			int y = particle.m_y * explosionHPos + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
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
