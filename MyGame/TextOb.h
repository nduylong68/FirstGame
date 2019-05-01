
#ifndef TEXTOB_H
#define TEXTOB_H

#include "BasicFunction.h"

class TextObject
{
public:
    TextObject();
    ~TextObject();

    enum TextColor
    {
        REDText = 0,
        WHITEText = 1,
        BLACKText = 2,
    };

    //bool LoadFromFile(string path);
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* scr);
    void Free();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);

    void RenderText(SDL_Renderer* scr, int x_p, int y_p,
                    SDL_Rect* clip = NULL, double angle=0.0,
                    SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


    int GetWidth() const {return Width_Of_Text;}
    int GetHeight() const {return Height_Of_Text;}

    void SetText(const string& text) { str = text;}
    string GetText() const {return str;}

private:
    string str;
    SDL_Color text_color;
    SDL_Texture* texture;
    int Width_Of_Text;
    int Height_Of_Text;
};

#endif // TEXTOB_H
