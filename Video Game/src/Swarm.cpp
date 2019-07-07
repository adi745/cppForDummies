/*
 * Swarm.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: adi
 */

#include "Swarm.h"

namespace sdlGraphics {

Swarm::Swarm():lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles; //because it's an array
}

void Swarm::update(int elapsed) {

	int interval = elapsed - lastTime;

	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}

} /* namespace sdlGraphics */
