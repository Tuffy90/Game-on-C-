#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
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

int main(){
    Map map = {20,20};
    Wall wall = {0,0,20,20};
    Food food = {rand() % map.w, rand() % map.h};
    Snake head = {10, 10};
    int vx = 1, vy = 0; 
    bool running = true;
    char buffer[3000];
    int n = 0;
    
    srand(time(NULL)); 

    while (running) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'w': if (vy == 0) { vx = 0; vy = -1; } break;
                case 's': if (vy == 0) { vx = 0; vy = 1; } break;
                case 'a': if (vx == 0) { vx = -1; vy = 0; } break;
                case 'd': if (vx == 0) { vx = 1; vy = 0; } break;
                case 'q': running = false; break;
            }
        }

        head.x += vx;
        head.y += vy;


        if (head.x <= 0 || head.x >= map.w - 1 || head.y <= 0 || head.y >= map.h - 1) {
            running = false; 
        }

        n = 0;
        printf("\033[H"); 
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
    Sleep(150); 
    }

    getchar();
    return 0;
}