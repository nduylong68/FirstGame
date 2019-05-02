#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include"BasicFunction.h"
#include "BasicObject.h"

class MainPlayer : public BaseObject
{
public:
    MainPlayer();
    ~MainPlayer();

    enum WalkType
    {
        walk_right = 2,
        walk_left = 1,
        stand_still = 0,

    };

    bool LoadImg(const char* path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des); // ham de show frame;
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen); // ham de nhan ban phim
    void set_clip(); // xu li ve animation

    void DoPlayer(); // ham de cong tru di luong cho nhan van di chuyen, can truyen vao ban do de check;
    void CheckToMap();

    bool on_ground;

    float getAngxPos() const {return x_pos;};
    float getAngyPos() const {return y_pos;};
    int getAngWidthFrame() const {return width_frame;};
    int getAngHeightFrame() const {return height_frame;};

    void SetPlayerSpeed(int NSpeed) { Player_Speed = NSpeed;} ;



private:
    float x_val; // khi an sang phai sang trai mot luong x
    float y_val; // giong tren nhung la len xuong

    float x_pos;
    float y_pos;

    int width_frame; //luu tru kich thuoc cua nhan vat
    int height_frame;

    SDL_Rect frame_clip[FrameSize]; // kich thuoc so frame
    Input Input_type;
    int frame; // bien luu chi so o frame xemd ang o frame nao;
    int status; // bien luu trang thai di chuyen;
    int Player_Speed;
    bool just_start;


} ;


#endif // MAINPLAYER_H

