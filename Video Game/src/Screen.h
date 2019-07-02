/*
 * Screen.h
 *
 *  Created on: Jun 29, 2019
 *      Author: adi
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL.h>


namespace sdlGraphics {
class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	/*in instance variables we often use a m_ prefix to declare that they are not local variables*/

public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	Screen();
	bool init();
	bool processEvents();
	void close();
	//virtual ~Screen();
};

} /* namespace sdlGraphics */

#endif /* SCREEN_H_ */
