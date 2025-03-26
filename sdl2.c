#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
uint16_t size_x = 680;
uint16_t size_y = 420;
int32_t multiplier=1;

double function(double i){
i = ((sin(i/32)*16))+multiplier;
return i;}


int main(){

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Init(SDL_INIT_VIDEO);
SDL_CreateWindowAndRenderer(size_x,size_y,0,&window,&renderer);
//SDL_RenderSetScale(renderer, 3,3);


//to get rid of 'not responding error'
SDL_Event event;

SDL_SetRenderDrawColor(renderer,0,0,0,255);
SDL_RenderClear(renderer);

SDL_SetRenderDrawColor(renderer,255,0,255,255);
int i=0;
do{


	SDL_PollEvent(&event);
	SDL_RenderDrawPoint(renderer,i,size_y*0.5-function(i));	
	SDL_RenderPresent(renderer);
	i++;
	if(event.key.keysym.sym==SDLK_SPACE)
		{
			i=0;
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer,255,0,255,255);
		}
	else if(event.key.keysym.sym==SDLK_f){
		multiplier++;
		printf("multiplier: %d\n",multiplier);
	}
	else if(event.key.keysym.sym==SDLK_j){
		multiplier--;
		printf("multiplier: %d\n",multiplier);
		}
	SDL_PollEvent(&event);
	SDL_Delay(10);


if(event.type==SDL_QUIT){exit(1);}
}
while(i<size_x);


return 0;}
