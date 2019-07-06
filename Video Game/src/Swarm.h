/*
 * Swarm.h
 *
 *  Created on: Jul 5, 2019
 *      Author: adi
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace sdlGraphics {

class Swarm {
private:
	Particle *m_pParticles;
public:
	const static int NPARTICLES = 5000;
	Swarm();
	virtual ~Swarm();
	void update();
	const Particle * const getParticles(){return m_pParticles;};
};

} /* namespace sdlGraphics */

#endif /* SWARM_H_ */
