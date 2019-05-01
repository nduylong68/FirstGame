#ifndef EXPLOSION_H
#define EXPLOSION_H

#include"BasicFunction.h"
#include"BasicObject.h"

class Explosion : public BaseObject
{
public:
    Explosion();
    ~Explosion();

    void set_clip();
    void set_frame(int fr) {Expl_frame = fr;};
    virtual bool LoadImg(const char* path, SDL_Renderer* scr);
    void Show(SDL_Renderer* scr);

    int get_Expl_frame_width() const {return Expl_frame_width;};
    int get_Expl_frame_height() const {return Expl_frame_height;};

private:
    int Expl_x_pos;
    int Expl_y_pos;
    int Expl_frame_width;
    int Expl_frame_height;
    int Expl_frame;
    SDL_Rect Expl_frame_clip[FrameSize];
};



#endif // EXPLOSION_H
