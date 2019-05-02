#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H

#include<windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<vector>
#include<iostream>
#include<chrono>
#include<thread>


using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//SCREEN
const int screen_width = 832;
const int screen_height = 704;
const int screen_BPP = 64; // chi so ve pixel

const int number_of_dragon = 7;

const int color_key_r = 0;
const int color_key_g = 255;
const int color_key_b = 255;

const int TILE_SIZE = 13;
const int MAX_MAP_X = 16;
const int MAX_MAP_Y = 11;

const int FrameSize = 8;

const int FRAME_PER_SEC = 45;






struct Input // cau truc danh cho viec di chuyen
{
    int left;
    int right;
    int up;
    int down;

};



namespace basicfunction
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    void ShowMenu(SDL_Renderer* scr, bool& MenuOff, TTF_Font* font, bool &quit);
    void RandomFunction(int &He, int& Sk);
    void ShowGameOver(SDL_Renderer*scr, bool& MenuOff, TTF_Font* font, bool &is_play);

}

#endif // BASICFUNCTION_H
