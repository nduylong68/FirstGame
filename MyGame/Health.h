
#ifndef HEALTH_H
#define HEALTH_H

#include"BasicFunction.h"

class Health
{
public:
    Health();
    ~Health();
     void Set_Rect (const int& health_x_pos, const int& health_y_pos) // ham dung de set kich thuoc cho rect
    {
        health_rect.x = health_x_pos ;
        health_rect.y = health_y_pos ;
    }

    SDL_Rect GetRect() const { return health_rect; } // ham lay ra size cua hinh anh
    SDL_Texture* GetObject() const { return health_object;} // ham lay ra hinh anh
    bool LoadImg(const char* path, SDL_Renderer* screen); // virtual the hien day la ham ao;

    void InitHealth(SDL_Renderer* screen);

    void SetClip(int healthbar);


    void Render_Health( int life, SDL_Renderer* screen, SDL_Rect* clip );
    void Free();


private:
    SDL_Texture* health_object; // bien chuyen luu tru hinh anh
    SDL_Rect health_rect;
    SDL_Rect health_clip;

};


#endif // HEALTH_H
