/*
 * Swarm.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: adi
 */

#include "Swarm.h"

namespace sdlGraphics {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles; //because it's an array
}

void Swarm::update() {
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}

} /* namespace sdlGraphics */
