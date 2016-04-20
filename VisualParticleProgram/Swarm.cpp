#include "Swarm.h"


namespace particle {
	Swarm::Swarm(): lastTickTime(0) {
		m_pParticles = new Particle[NPARTICLES];
	}


	Swarm::~Swarm() {
		delete[] m_pParticles;
	}

	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTickTime;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}

		lastTickTime = elapsed;
	}
}
