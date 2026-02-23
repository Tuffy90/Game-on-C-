#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#define VERSION "0.0.1 Alpha"
#define WIDTH 10
#define HEIGHT 10
#define WALL '#' 
#define EMPTY ' '
#define HEAD 'H'
#define FOOD 'F'

typedef struct{
    int w;
    int h;
}Map;

typedef struct{
    int x;
    int y;
}Snake;

typedef struct{
    int Fx;
    int Fy;
}Food;

typedef struct{
    int Wx;
    int Wy;
    int Ww;
    int Wh;
}Wall;

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_VIDEO)< 0){
        printf("SDL ERROR", SDL_GetError());
        return 1;
    }
    Map map = {20,20};
    Wall wall = {0,0,20,20};
    Food food = {rand() % map.w, rand() % map.h};
    Snake head = {5,5};
    bool running = true;
    char buffer [3000];
    int n = 0;
    printf("\033[H");

    SDL_Event event;
   while(running){
    n = 0;
    system("cls");
    while(SDL_PollEvent(&event)){
     if (event.type == SDL_QUIT) running = false;
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_ESCAPE: 
                running = false; 
                break;
                case SDLK_UP:
                head.y--;
                break;
                case SDLK_DOWN:
                head.y++;
                break;
                case SDLK_LEFT:
                head.x--;
                break;
                case SDLK_RIGHT:
                head.x++;
                break;
            }
        }
     }
     for(int i = 0; i < map.w; i++){
        for(int j = 0; j < map.h; j++){
            if(i == head.y && j == head.x) buffer[n++] = 'H';
            else if(i == food.Fy && j == food.Fx) buffer[n++] = 'F';
            else if(i == 0 || i == map.h - 1 || j == 0 || j == map.w - 1) buffer[n++] = '#';
            else buffer[n++] = ' ';
        }
        buffer[n++] = '\n';
    }
    buffer[n] = '\0';
    printf("%s", buffer); 
     SDL_Delay(500);
    }

    getchar();
    return 0;
}