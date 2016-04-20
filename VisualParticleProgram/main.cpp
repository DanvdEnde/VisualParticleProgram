#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <ctime>
#include "Swarm.h"
#undef main

using namespace std;
using namespace particle;

int main() {
	srand(time(nullptr));

	Screen screen;

	if (screen.init() == false)
		cout << "Error initialising SDL." << endl;

	Swarm swarm;

	while (true) {
		int elapsed = SDL_GetTicks();

		// Update particles
		swarm.update(elapsed);

		// Draw particles
		unsigned char red = (1 + sin(elapsed * 0.0003)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0002)) * 128;

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		// Draw Box Blur
		screen.boxBlur();

		// Draw the screen.
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false)
			break;
	}

	screen.close();

	return 0;
}