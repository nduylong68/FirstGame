

#include"BasicFunction.h"
#include"BasicObject.h"
//#include"MapGame.h"
#include"MainPlayer.h"
#include"Dragon.h"
#include"Timer.h"
#include"TextOb.h"
#include "Health.h"
#include"Explosion.h"

using namespace std;
BaseObject g_background;
BaseObject Healing;
BaseObject Skill;

TTF_Font* font_score = NULL;
TTF_Font* font_menu = NULL;
int Dragon_Speed = 8.0;
int New_Speed = 8;
bool SpeedUp = false;
Mix_Music* music_low = NULL;
Mix_Music* music_fast = NULL;
Mix_Chunk* healing_sound = NULL;
Mix_Chunk* Collision_sound = NULL;
Mix_Chunk* Skill_sound = NULL;
Mix_Chunk* GameOver_sound = NULL;

bool InitData()
{
    bool result = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Go Go Angel !!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                                        screen_width, screen_height,SDL_WINDOW_SHOWN);

    if(g_window == NULL)
    {
        result = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window,-1, SDL_RENDERER_ACCELERATED);
            if(g_screen == NULL) result = false;
            else
            {
                SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
                int imgFlags = IMG_INIT_PNG;
                if ( !( IMG_Init(imgFlags) && imgFlags ) ) // <==> Neu IMG_Init(imgFlags) == false && imgFlags == false
                    {
                        result = false;
                    }

            }
            if (TTF_Init() == -1 )
            {
                result = false;
            }

            font_score = TTF_OpenFont("font/halo.ttf", 35);
            if (font_score == NULL)
            {
                cout << "Can't find font for score" << endl;
                result = false;
            }

            font_menu = TTF_OpenFont("font/menu.ttf", 40);
            if (font_menu == NULL)
            {
                cout << "Can't find font for menu" << endl;
                result = false;
            }

            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
                    result = false;
                }

            music_low = Mix_LoadMUS("Audio/GameLowSound.wav");
            music_fast = Mix_LoadMUS("Audio/GameFastSound.wav");
            healing_sound = Mix_LoadWAV("Audio/Healing.wav");
            Collision_sound = Mix_LoadWAV("Audio/Collision.wav");
            Skill_sound = Mix_LoadWAV("Audio/SkillandExplo.wav");
            GameOver_sound = Mix_LoadWAV("Audio/GameOver.wav");


    }

    return result;
}


bool Load_Background()
{
    bool Backgroundload = g_background.LoadImg("Pic/Background.png",g_screen);

    return Backgroundload;

}

/*bool Load_Menu()
{
    bool Menuload = Menu_pic.LoadImg("Pic/Menu.png",g_screen);

    return Menuload;

} */




void Close()  // ham tat tat ca cac chuong trinh di.
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;

    TTF_CloseFont(font_menu);
    TTF_CloseFont(font_score);

    Mix_FreeMusic(music_low);
    music_low = NULL;

    Mix_FreeMusic(music_fast);
    music_fast = NULL;

    Mix_FreeChunk(healing_sound);
    healing_sound = NULL;

    Mix_FreeChunk(Collision_sound);
    Collision_sound = NULL;

    Mix_FreeChunk(Skill_sound);
    Skill_sound = NULL;

    Mix_FreeChunk(GameOver_sound);
    GameOver_sound = NULL;

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();

}


int main(int argc, char* argv[] ) {

    Timer fps_timer;
    if (InitData() == false) return -1;


    bool MenuOff = false;

    bool is_quit = false;

    bool is_playing = false;



    if (Load_Background() == false ) return -1;


    //GameMap game_map;
    //game_map.LoadMap("map/map.dat");
    //game_map.LoadTiles(g_screen);

  while (is_quit == false)
  {


    MainPlayer p_player;
    p_player.LoadImg("Pic/player_stand.png", g_screen);
    p_player.set_clip();

    Healing.LoadImg("pic/Healing.png", g_screen);
    Healing.Set_Rect(200, 20);

    Skill.LoadImg("Pic/Skill.png", g_screen);
    Skill.Set_Rect(325,20);

    Health Ang_health;
    Ang_health.InitHealth(g_screen);


    Dragon* dra_threats = new Dragon[number_of_dragon];
    for(int t = 0; t < number_of_dragon; t++)
    {
    Dragon* dra_threat =  ( dra_threats + t );
    dra_threat->LoadImg("Pic/dragon_sprite.png", g_screen);
    dra_threat->set_clips();
    dra_threat->SetYVal(8.0);
    }

    Explosion* Expl_things = new Explosion[number_of_dragon];
    for(int t = 0; t< number_of_dragon; t++)
    {
        Explosion* Expl_thing = (Expl_things + t);
        Expl_thing->LoadImg("Pic/Explosion.png", g_screen);
        Expl_thing->set_clip();
    }

    TextObject score_game;
    score_game.SetColor(TextObject::WHITEText);

    TextObject HealingText;
    HealingText.SetColor(TextObject::WHITEText);

    TextObject SkillText;
    SkillText.SetColor(TextObject::WHITEText);

    fps_timer.start();

    int Life = 1000;

    int health_bar = 195;

    if(MenuOff == false && is_playing == false)
    {
    basicfunction::ShowMenu(g_screen, MenuOff, font_menu, is_quit);
    }

    is_playing = true;

    int score_val = 0;

    int HealingNum = 0;
    int SkillNum = 0;

    while( MenuOff == true && is_quit != true && is_playing == true)
    {
        bool Skilling = false;
        if (Mix_PlayingMusic() == 0)
        {
                Mix_PlayMusic(music_low, -1);
            if (Dragon_Speed > 15 );
            {
                Mix_HaltMusic();
                Mix_PlayMusic(music_fast, -1);

            }
        }

        while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                is_quit = true;
                cout << " Shut down" << endl;
            }
            if(g_event.type == SDL_KEYDOWN)
            {
                switch(g_event.key.keysym.sym)
                {
                case SDLK_UP:
                    {
                        if( HealingNum > 0 && Life < 1000)
                        {
                            Life += 200;
                            if (Life > 1000) Life = 1000;
                            HealingNum -= 1;
                            Mix_PlayChannel(-1,healing_sound,0);
                            health_bar += 14 * 2;
                            if (health_bar > 195) health_bar = 195;
                            Ang_health.SetClip(health_bar);

                        }
                        break;
                    }
                case SDLK_DOWN:
                    {
                        if (SkillNum >0)
                        {
                            Skilling = true;
                        }
                    }
                }
            }

            p_player.HandleInputAction(g_event, g_screen);
        }


        SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
        SDL_RenderClear(g_screen);

       g_background.Render(g_screen, NULL);
       Healing.Render(g_screen, NULL);
       Skill.Render(g_screen, NULL);

       string HealingStr = to_string(HealingNum);
       string SkillStr = to_string(SkillNum);

       HealingText.SetText(HealingStr);
       SkillText.SetText(SkillStr);

       HealingText.LoadFromRenderText(font_score, g_screen);
       HealingText.RenderText(g_screen, 240, 20);

       SkillText.LoadFromRenderText(font_score, g_screen);
       SkillText.RenderText(g_screen, 370, 20);

        if (Skilling == true)
        {

            Mix_PauseMusic();
            Mix_PlayChannel(-1, Skill_sound, 0);
            p_player.Show(g_screen);
            for( int i = 0; i< number_of_dragon; i++ )
                {
                    Dragon* dra_threat = (dra_threats + i);
                    Explosion* Expl_thing = (Expl_things + i);
                    int x_pos_E = dra_threat->GetDraxPos();
                    int y_pos_E = dra_threat->GetDrayPos();
                    for (int j = 0; j < FrameSize; j++)
                    {
                    Expl_thing->set_frame(j);
                    Expl_thing->Set_Rect(x_pos_E, y_pos_E);
                    Expl_thing->Show(g_screen);
                    SDL_RenderPresent(g_screen);
                    }
                    dra_threat->SetDra_Pos();

                }

                SkillNum -= 1;
                Mix_ResumeMusic();
                Skilling = false;
        }

        if (Skilling == false)
        { p_player.DoPlayer(); }
        p_player.Show(g_screen);

        Ang_health.Render_Health(health_bar, g_screen, NULL);

        if (SpeedUp == true &&Dragon_Speed <= 50)
        {
            Dragon_Speed += 2 ;
            New_Speed += 3;
            p_player.SetPlayerSpeed(New_Speed);
        }


        for (int tt =0; tt< number_of_dragon; tt++)
        {

            Dragon* dra_threat = (dra_threats + tt);
            if (dra_threat)
            {
                if (SpeedUp == true)
                {
                    dra_threat->SetYVal(Dragon_Speed);
                }
            dra_threat->Show(g_screen);
            if(Skilling == false)
            {
            dra_threat->DragonMove(screen_width, screen_height);
            }
            }
        }

         SpeedUp = false;

        for (int k = 0; k< number_of_dragon; k++)
        {
            Dragon* dr_threat = (dra_threats + k);
            if(dr_threat != NULL)
            {
                SDL_Rect DraRect;
                DraRect.x = dr_threat->GetDraxPos();
                DraRect.y = dr_threat->GetDrayPos();
                DraRect.w = dr_threat->getDraWidthFrame();
                DraRect.h = dr_threat->getDraHeightFrame();

                SDL_Rect AngRect;
                AngRect.x = p_player.getAngxPos();
                AngRect.y = p_player.getAngyPos();
                AngRect.w = p_player.getAngWidthFrame();
                AngRect.h = p_player.getAngHeightFrame();

                bool cCollision = basicfunction::CheckCollision(AngRect, DraRect);
                if (cCollision)
                {
                    dr_threat->SetDra_Pos();
                    Mix_PlayChannel(-1,Collision_sound,0);
                    Life -= 300;
                    health_bar -= 14*3;
                    Ang_health.SetClip(health_bar);
                }
            }
        }

        if (Life <= 0)
                    {
                        Mix_HaltMusic();
                        cout << Mix_PlayingMusic() << endl;
                        cout << "Die" << endl;
                        is_playing = false;
                        Mix_PlayChannel(-1,GameOver_sound, 0);
                    }

        //Show Score
        string str_score = "Score: ";
        score_val +=  1; //SDL_GetTicks() / 100 - time_start/100;
        string str_val = to_string(score_val);
        str_score += str_val;

        score_game.SetText(str_score);
        score_game.LoadFromRenderText(font_score, g_screen);
        score_game.RenderText(g_screen, screen_width - 270, 15);

        if (score_val % 200 == 0 && score_val != 0)
        {
            basicfunction::RandomFunction(HealingNum, SkillNum);

        }


        //Speed Up for threat
        if(score_val % 300 == 0 && score_val != 0)
        {
            SpeedUp = true;
        }


        SDL_RenderPresent(g_screen);

        int real_time = fps_timer.get_ticks();
        int time_a_frame = 1000/FRAME_PER_SEC; //1000 la milisec

        if (real_time < time_a_frame)
        {
            int delay_time = time_a_frame - real_time;
            if (delay_time > 0)
            {
            //SDL_Delay(delay_time);
            }
        }
    }

    Ang_health.Free();

    Healing.Free();
    Skill.Free();
    score_game.Free();


    p_player.Free();
    for (int k = 0; k< number_of_dragon; k++)
        {
            Dragon* dr_threat = (dra_threats + k);
            if(dr_threat != NULL)
            { dr_threat ->Free(); }
        }

     delete [] dra_threats;
     delete [] Expl_things;

       if (is_playing == false)
        {
            basicfunction::ShowGameOver(g_screen, MenuOff, font_menu, is_playing);
        }
    HealingText.Free();
    SkillText.Free();

  }



    Close();
    return 0;
}
