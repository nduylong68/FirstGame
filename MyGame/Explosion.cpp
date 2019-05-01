#include "Explosion.h"

Explosion::Explosion()
{
    Expl_frame_width = 0;
    Expl_frame_height = 0;
    Expl_frame = 0;
    Expl_x_pos = 0;
    Expl_y_pos = 0;

}

Explosion::~Explosion()
{

}

bool Explosion::LoadImg(const char* path, SDL_Renderer* scr)
{
    bool ret = BaseObject::LoadImg(path, scr);

    if(ret)
    {
        Expl_frame_width = rect_object.w / FrameSize;
        Expl_frame_height = rect_object.h;
    }
    else { cout << "Cannot find Explosion image " << endl;}

    return ret;
}

void Explosion::set_clip()
{
      if(Expl_frame_width> 0 && Expl_frame_height > 0)
    {   for(int i =0; i < FrameSize; i++)
        {
            Expl_frame_clip[i].x = i * Expl_frame_width;
            Expl_frame_clip[i].y = 0;
            Expl_frame_clip[i].w = Expl_frame_width;
            Expl_frame_clip[i].h = Expl_frame_height;
        }
    }
}

void Explosion::Show(SDL_Renderer* scr)
{
    LoadImg("Pic/Explosion.png", scr);

    SDL_Rect* current_clip = &Expl_frame_clip[Expl_frame];
    SDL_Rect render_quad = {rect_object.x, rect_object.y, Expl_frame_width, Expl_frame_height};
    if(current_clip != NULL)
    {
        render_quad.w = current_clip->w;
        render_quad.h = current_clip->h;
    }
    SDL_RenderCopy(scr, p_object, current_clip, &render_quad);
    SDL_DestroyTexture(p_object);
    this_thread::sleep_for(chrono::milliseconds(70));
}
