   #include <iostream>
	#include <SDL2/SDL.h>
	using namespace std;

    void getKey(bool &keyDown, SDL_Event &event){
    	SDL_PollEvent(&event);
    	if(event.type == SDL_KEYDOWN){
    		keyDown = true;
    	}
    	if(event.type == SDL_KEYUP) {
    		keyDown = false;
    	}
    }
    int main(){
    	char input;
    	SDL_SetMainReady();
    	SDL_Init(SDL_INIT_VIDEO);
    	SDL_Window* window =  SDL_CreateWindow("c",40,30,500,500,0);
    	bool swit = false;
    	Uint8* keyArray;
        SDL_Event event;
        const Uint8 *state = SDL_GetKeyboardState(NULL);

        while(1){
        	SDL_PollEvent(&event);

        	if (state[SDL_SCANCODE_A]) {
        	    printf("<RETURN> is pressed.\n");
        	}
        	if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
        	    printf("Right and Up Keys Pressed.\n");
        	}
        }

        SDL_Quit();
        	
        return 0;
        }
