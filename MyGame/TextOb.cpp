#include "TextOb.h"

TextObject::TextObject()
{
    text_color.r = 255;
    text_color.g = 255;
    text_color.b = 255;
    texture = NULL;
}

TextObject::~TextObject()
{

}

bool TextObject::LoadFromRenderText(TTF_Font* font, SDL_Renderer* scr)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, str.c_str(), text_color);
    if (text_surface)
    {
        texture = SDL_CreateTextureFromSurface(scr,text_surface);
        Width_Of_Text = text_surface->w;
        Height_Of_Text= text_surface->h;

        SDL_FreeSurface(text_surface);
    }

    return texture != NULL;
}

void TextObject::Free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void TextObject::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    text_color.r = red;
    text_color.g = green;
    text_color.b = blue;
}

void TextObject::SetColor(int type)
{
    if(type == REDText)
    {
       SDL_Color color = {255, 0, 0};
       text_color = color;
    }
    else if (type == WHITEText)
    {
        SDL_Color color = {255, 255, 255};
        text_color = color;
    }
    else if( type == BLACKText)
    {
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }

}

void TextObject::RenderText(SDL_Renderer* scr, int x_p, int y_p,
                    SDL_Rect* clip , double angle,
                    SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x_p, y_p, Width_Of_Text, Height_Of_Text};
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(scr, texture, clip, &renderQuad, angle,center, flip);

}
