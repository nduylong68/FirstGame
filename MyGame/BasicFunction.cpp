#include "BasicFunction.h"
#include "BasicObject.h"
#include "TextOb.h"


bool basicfunction::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x + 17;
    int right_a = object1.x + object1.w - 17;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    if (top_b < (bottom_a - 10) && bottom_b > (top_a + 10) )
    {
        if(left_b < (right_a - 10) && right_b > right_a)
        {
            return true;
        }

        if( left_b < left_a && right_b > (left_a +10) )
        {
            return true;
        }
    }

  return false;
}

void basicfunction::ShowMenu(SDL_Renderer* scr, bool& Menu, TTF_Font* font, bool &quit)
{
    Mix_Music* menu_music;

    BaseObject Img_Menu;
    Img_Menu.LoadImg("Pic/Menu.png", scr);


     int MenuChoiceNum = 2;
    SDL_Rect PosofMenu[MenuChoiceNum];
    PosofMenu[0].x = 340;
    PosofMenu[0].y = 400;
    PosofMenu[1].x = 340;
    PosofMenu[1].y = 500;

    TextObject TextMenu[MenuChoiceNum];

    TextMenu[0].SetColor(255, 0, 0);
    TextMenu[0].SetText("Play");
    TextMenu[0].LoadFromRenderText(font, scr);


    TextMenu[1].SetColor(255, 255, 255);
    TextMenu[1].SetText("Exit");
    TextMenu[1].LoadFromRenderText(font, scr);

    menu_music = Mix_LoadMUS("Audio/Menu_sound.wav");
    if (menu_music == NULL)
    {
        cout << "Cannot Load music for menu" << endl;
    }


    int Selection = 0;

    SDL_Event Menu_Choice;

    while (Menu == false)
    {

        SDL_RenderClear(scr);
        SDL_SetRenderDrawColor(scr, 255, 255, 255, 255);
        Img_Menu.Render(scr, NULL);

        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(menu_music, -1);
        }

        TextMenu[0].RenderText(scr, PosofMenu[0].x, PosofMenu[0].y);
        TextMenu[1].RenderText(scr, PosofMenu[1].x, PosofMenu[1].y);

        while (SDL_PollEvent(&Menu_Choice))
        {
          if (Menu_Choice.type == SDL_KEYDOWN)
          {
              switch(Menu_Choice.key.keysym.sym)
              {
              case SDLK_DOWN:
              case SDLK_UP:

                {
                    if (Selection == 0)
                    {
                        Selection =1;
                        TextMenu[1].SetColor(255, 0, 0);
                        TextMenu[0].SetColor(255, 255, 255);
                        TextMenu[0].LoadFromRenderText(font, scr);
                        TextMenu[1].LoadFromRenderText(font, scr);
                        TextMenu[0].RenderText(scr, PosofMenu[0].x, PosofMenu[0].y);
                        TextMenu[1].RenderText(scr, PosofMenu[1].x, PosofMenu[1].y);
                    }
                    else if (Selection == 1)
                    {
                        Selection = 0;
                        TextMenu[0].SetColor(255, 0, 0);
                        TextMenu[1].SetColor(255, 255, 255);
                        TextMenu[0].LoadFromRenderText(font, scr);
                        TextMenu[1].LoadFromRenderText(font, scr);
                        TextMenu[0].RenderText(scr, PosofMenu[0].x, PosofMenu[0].y);
                        TextMenu[1].RenderText(scr, PosofMenu[1].x, PosofMenu[1].y);

                    }
                    break;
                }
              case SDLK_RETURN:
                {
                    if (Selection == 0)
                    {
                        Mix_FreeMusic(menu_music);
                        menu_music = NULL;
                        TextMenu[0].Free();
                        TextMenu[1].Free();
                        Img_Menu.Free();
                        Menu = true;

                    }
                    else if (Selection == 1)
                    {
                        Mix_FreeMusic(menu_music);
                        menu_music = NULL;
                        TextMenu[0].Free();
                        TextMenu[1].Free();
                        Img_Menu.Free();
                        Menu = true;
                        quit = true;
                    }
                    break;
                }
              }
          }

          else if (Menu_Choice.type == SDL_QUIT)
          {
                        Mix_FreeMusic(menu_music);
                        menu_music = NULL;
                        TextMenu[0].Free();
                        TextMenu[1].Free();
                        Img_Menu.Free();
                        Menu = true;
                        quit = true;
          }
        }

         SDL_RenderPresent(scr);
    }

}

void basicfunction::RandomFunction(int& He, int& Sk)
{
    int ChooseSkill = rand()%10;
    switch (ChooseSkill)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:

        {
            He += 1;
            break;
        }
    case 7:
    case 8:
    case 9:
        {
            Sk += 1;
            break;
        }
    }
}


void basicfunction::ShowGameOver(SDL_Renderer* scr, bool& MenuOff, TTF_Font* font, bool& is_play)
{
    Mix_Music* end_music;
    Mix_HaltMusic();

    BaseObject Img_End;
    Img_End.LoadImg("Pic/Trymore.png", scr);


     int EndChoiceNum = 2;
    SDL_Rect PosofEnd[EndChoiceNum];
    PosofEnd[0].x = 60;
    PosofEnd[0].y = 600;
    PosofEnd[1].x = 500;
    PosofEnd[1].y = 600;

    TextObject TextEnd[EndChoiceNum];

    TextEnd[0].SetColor(TextObject::REDText);
    TextEnd[0].SetText("Yes !!!!");
    TextEnd[0].LoadFromRenderText(font, scr);


    TextEnd[1].SetColor(TextObject::WHITEText);
    TextEnd[1].SetText("Main Menu");
    TextEnd[1].LoadFromRenderText(font, scr);

    end_music = Mix_LoadMUS("Audio/PlAgain.wav");
    if (end_music == NULL)
    {
        cout << "Cannot Load music for ending" << endl;
    }


    int Selection = 0;

    SDL_Event End_Choice;

    while (is_play == false && MenuOff == true)
    {

        SDL_RenderClear(scr);
        SDL_SetRenderDrawColor(scr, 255, 255, 255, 255);
        Img_End.Render(scr, NULL);

        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(end_music, -1);
        }

        TextEnd[0].RenderText(scr, PosofEnd[0].x, PosofEnd[0].y);
        TextEnd[1].RenderText(scr, PosofEnd[1].x, PosofEnd[1].y);

        while (SDL_PollEvent(&End_Choice))
        {
          if (End_Choice.type == SDL_KEYDOWN)
          {
              switch(End_Choice.key.keysym.sym)
              {
              case SDLK_LEFT:
              case SDLK_RIGHT:

                {
                    if (Selection == 0)
                    {
                        Selection =1;
                        TextEnd[1].SetColor(255, 0, 0);
                        TextEnd[0].SetColor(255, 255, 255);
                        TextEnd[0].LoadFromRenderText(font, scr);
                        TextEnd[1].LoadFromRenderText(font, scr);
                        TextEnd[0].RenderText(scr, PosofEnd[0].x, PosofEnd[0].y);
                        TextEnd[1].RenderText(scr, PosofEnd[1].x, PosofEnd[1].y);
                    }
                    else if (Selection == 1)
                    {
                        Selection = 0;
                        TextEnd[0].SetColor(255, 0, 0);
                        TextEnd[1].SetColor(255, 255, 255);
                        TextEnd[0].LoadFromRenderText(font, scr);
                        TextEnd[1].LoadFromRenderText(font, scr);
                        TextEnd[0].RenderText(scr, PosofEnd[0].x, PosofEnd[0].y);
                        TextEnd[1].RenderText(scr, PosofEnd[1].x, PosofEnd[1].y);

                    }
                    break;
                }
              case SDLK_RETURN:
                {
                    if (Selection == 0)
                    {
                        Mix_FreeMusic(end_music);
                        end_music = NULL;
                        TextEnd[0].Free();
                        TextEnd[1].Free();
                        Img_End.Free();
                        is_play = true;

                    }
                    else if (Selection == 1)
                    {
                        Mix_FreeMusic(end_music);
                        end_music = NULL;
                        TextEnd[0].Free();
                        TextEnd[1].Free();
                        Img_End.Free();
                        MenuOff = false;
                        is_play = false;
                    }
                    break;
                }
              }
          }

          else if (End_Choice.type == SDL_QUIT)
          {
                        Mix_FreeMusic(end_music);
                        end_music = NULL;
                        TextEnd[0].Free();
                        TextEnd[1].Free();
                        Img_End.Free();
                        MenuOff = true;
                        is_play = false;
          }
        }

         SDL_RenderPresent(scr);
    }
}


