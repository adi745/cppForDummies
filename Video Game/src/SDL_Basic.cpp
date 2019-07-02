//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout << "SDL init failed" << endl;

		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Particle Fire Explostion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	/*it really helps watching the API and tutorials and typing it out*/
	// Check that the window was successfully created
	if (window == NULL){
		SDL_Quit();
		cout << "Could not create a window, error code: " << SDL_GetError() <<endl;
		return 2;
		/*NULL is often used and is created from std*/
	}

	/*in games you have an infinite loop which runs all the time - like dispatcher timer*/

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	//gurarentee the rendering with the same frequency of the eye to prevent distortion
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(renderer == NULL){
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	// need to handle that repetition of code
	if(texture == NULL){
		cout << "Could not create texture"<<endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}
	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	/*buffer to contain all the information for rendering, an array of Uint32
	basically an int but guarenteed to be 32 bit - 4 bytes*/
	/*first we'll write some info to the pixel's using memset*/
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	/*memset does the same thing like a for loop for all pixels*/

	buffer[30000] = 0xFFFFFFFF; //setting an Uint32 to FF
	for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++){
		buffer[i] = 0xFFFF0000;
	}
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Event event;
	bool quit = false;

	while(!quit){
		//update particles
		//Draw particles
		//Check for messages/events
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				/*the QUIT event is raised
				every time someone is quitting or closing the window*/
				quit = true;
			}

		}
	}

	delete [] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
