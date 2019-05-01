#include"Dragon.h"
#include"MainPlayer.h"
#include"BasicFunction.h"
#include"BasicObject.h"


Dragon::Dragon()
{
    drag_speed = 0.8;
    dra_frame = 0;
    dra_x_pos = 0;
    dra_y_pos = screen_height;
    dra_width_frame = 0;
    dra_height_frame = 0;

    x_val = 0;
    y_val = 0;
}


Dragon::~Dragon()
{

}

bool Dragon::LoadImg(const char* path, SDL_Renderer* screen)
{

    bool ret = BaseObject::LoadImg(path, screen);
    if (ret == true)
    {
        dra_width_frame = rect_object.w / FrameSize;
        dra_height_frame = rect_object.h;
    }
    else {cout << "Can not load img of dra" << endl;}

    return ret;
}

void Dragon::set_clips()
{
    if(dra_width_frame > 0 && dra_height_frame > 0)
    {   for(int i =0; i < FrameSize; i++)
        {
            dra_frame_clip[i].x = i * dra_width_frame;
            dra_frame_clip[i].y = 0;
            dra_frame_clip[i].w = dra_width_frame;
            dra_frame_clip[i].h = dra_height_frame;
        }
    }
    else cout <<"Dra_frame is not valid" << endl;
}

void Dragon::Show(SDL_Renderer* des)
{
    LoadImg("Pic/dragon_sprite.png", des);
    dra_frame++ ;
    if(dra_frame > 8)
    {
        dra_frame = 0;
    }
    rect_object.x = dra_x_pos ;//- map_x;
    rect_object.y = dra_y_pos;// - map_y;

    SDL_Rect* current_clip = &dra_frame_clip[dra_frame];

    SDL_Rect renderQuad = {rect_object.x, rect_object.y, dra_width_frame, dra_height_frame}; // chua toa do dang o va kich thuoc

    SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
    SDL_DestroyTexture(p_object);
}


void Dragon::SetDra_Pos()
{
        int time_sleep = rand()%50;
        dra_y_pos = screen_height + time_sleep*20;
        int rand_x = rand() % (screen_width - 110);
        dra_x_pos = rand_x;
}

void Dragon::DragonMove(const float x_max, const float y_max)
{
    dra_y_pos -= y_val;
    if (dra_y_pos < -68)
    {
        SetDra_Pos();
    }


}



