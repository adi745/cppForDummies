/*
 * Particle.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: adi
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace sdlGraphics {

Particle::Particle(): m_x(0), m_y(0) {
	m_direction = (2 * M_PI *rand())/RAND_MAX;
	m_speed = (0.0001*rand())/RAND_MAX;

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {
	double m_xspeed = m_speed * cos(m_direction);
	double m_yspeed = m_speed * sin(m_direction);
	m_x += m_xspeed * interval;
	m_y += m_yspeed * interval;

	if (m_x <= -1.0 || m_x >= 1.0) {
		m_xspeed = -m_xspeed;
	}
	if (m_y <= -1.0 || m_y >= 1.0) {
		m_yspeed = -m_yspeed;
	}
}

} /* namespace sdlGraphics */
