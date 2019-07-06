/*
 * Particle.h
 *
 *  Created on: Jul 5, 2019
 *      Author: adi
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace sdlGraphics {

struct Particle {
	double m_x, m_y, m_speed, m_direction;
public:
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace sdlGraphics */

#endif /* PARTICLE_H_ */
