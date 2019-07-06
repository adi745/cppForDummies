/*
 * Screen.cpp
 *
 *  Created on: Jun 29, 2019
 *      Author: adi
 */

#include "Screen.h"

namespace sdlGraphics {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
	// TODO Auto-generated constructor stub
}

bool Screen::init() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explostion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	/*it really helps watching the API and tutorials and typing it out*/
	// Check that the window was successfully created
	if (m_window == NULL) {
		SDL_Quit();
		return false;
		/*NULL is often used and is created from std*/
	}

	/*in games you have an infinite loop which runs all the time - like dispatcher timer*/

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	//gurarentee the rendering with the same frequency of the eye to prevent distortion
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	// need to handle that repetition of code
	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	 m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	/*buffer to contain all the information for rendering, an array of Uint32
	 basically an int but guarenteed to be 32 bit - 4 bytes*/
	/*first we'll write some info to the pixel's using memset*/
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	/*memset does the same thing like a for loop for all pixels*/

	/*m_buffer[30000] = 0xFFFFFFFF; //setting an Uint32 to FF
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0xFFFF0000;
	}*/
	/*SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	 SDL_RenderClear(m_renderer);
	 SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	 SDL_RenderPresent(m_renderer);*/
	return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	Uint32 color = 0;

	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
		return;
	}
	color += red;
	color <<= 8; //move all the values of the color by 8 bits
	color += green;
	color <<= 8; //move all the values of the color by 8 bits
	color += blue;
	color <<= 8; //move all the values of the color by 8 bits
	color += 0xFF; //inserting the alpha value which by this value means opaque

	m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::clear(){
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	/*clearing the buffer using null array the size of the screen*/
}

bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			/*the QUIT event is raised
			 every time someone is quitting or closing the window*/
			return false;
		}
	}
	return true;
}
void Screen::close() {
	delete[] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

/*Screen::~Screen() {
 // TODO Auto-generated destructor stub
 }*/

} /* namespace sdlGraphics */
