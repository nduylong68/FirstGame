
#ifndef BASICOBJECT_H
#define BASICOBJECT_H

#include "BasicFunction.h"
#include<iostream>

using namespace std;

class BaseObject
{
public :
    BaseObject();
    ~BaseObject();

    void Set_Rect(const int& valueofx, const int& valueofy) // ham dung de set kich thuoc cho rect
    {
        rect_object.x = valueofx ;
        rect_object.y = valueofy ;
    }


    virtual bool LoadImg(const char* path, SDL_Renderer* screen); // virtual the hien day la ham ao;
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();


    SDL_Texture* p_object; // bien chuyen luu tru hinh anh
    SDL_Rect rect_object; // bien chuyen luu tru size cua hinh anh





};

#endif // BASICOBJECT_H
