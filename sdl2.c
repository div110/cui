#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
uint16_t size_x = 1280;
uint16_t size_y = 680;


double function(double i){
i = sin(i/32)*16;
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

for(int i=0;i<size_x||function(i)<size_y;i++){
SDL_PollEvent(&event);

SDL_RenderDrawPoint(renderer,i,size_y*0.5-function(i));

SDL_RenderPresent(renderer);
SDL_Delay(10);
}


return 0;}
