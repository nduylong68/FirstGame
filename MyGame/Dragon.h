#ifndef DRAGON_H
#define DRAGON_H

#include"BasicFunction.h"
#include"BasicObject.h"
#include"MainPlayer.h"

class Dragon : public BaseObject
{
public:
    Dragon();
    ~Dragon();

    bool LoadImg(const char* path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des); // ham de show frame;
    void set_clips(); // xu li ve animation

   void DragonMove(const float x_max, const float y_max);

   void SetXVal(float val) {x_val = val;};
   void SetYVal(float val) {y_val = val;};
   float Get_x_val() const {return x_val;};
   float Get_y_val() const {return y_val;};

   float GetDraxPos() const {return dra_x_pos;};
   float GetDrayPos() const {return dra_y_pos;};

   int getDraWidthFrame() const {return dra_width_frame;};
   int getDraHeightFrame() const {return dra_height_frame;};

   void SetDra_Pos();

private:
    int map_x, map_y;
    float dra_x_pos, dra_y_pos, x_val, y_val;
    int dra_width_frame;
    int dra_height_frame;
    int drag_speed;
    SDL_Rect dra_frame_clip[FrameSize];
    int dra_frame;
};




#endif // DRAGON_H
