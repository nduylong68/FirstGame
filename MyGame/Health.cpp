#include "Health.h"

Health::Health()
{
    health_object = NULL;
    health_rect.x = 0;
    health_rect.y = 0;
    health_rect.w = 0;
    health_rect.h = 0;

    health_clip.x = 0;
    health_clip.y = 0;
    health_clip.w = 195;
    health_clip.h = 49;
}

Health::~Health()
{
    Free();
}


bool Health::LoadImg(const char* path, SDL_Renderer* screen)
{
     SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path);
    if (load_surface == NULL) { cout << " FAIL TO LOAD SURFACE !!" << endl; }
    else {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, color_key_r, color_key_g, color_key_b));
        // Color key dung de xoa di phan background trong anh cua nhan vat

        new_texture = SDL_CreateTextureFromSurface(screen, load_surface); // Dung de chuyen surface thanh texture

        if (new_texture == NULL)
        {   cout << "Fail to convert surface into texture !!" << endl;
            printf("SDL_Init failed: %s\n", SDL_GetError()) ;
        }
        else {
            health_rect.w = load_surface -> w;
            health_rect.h = load_surface -> h;
            // dung  de gan thong so cua tam anh vao BaseObject
        }

        SDL_FreeSurface(load_surface); // xoa surface vi thong so cua surface da chuyen sang new_texture
    }

    health_object = new_texture;

    if (health_object != NULL) { return true;}
    else { return false;}
}

void Health::SetClip(int healthbar)
{
    health_clip.w = healthbar;

}

void Health::Render_Health( int life, SDL_Renderer* screen, SDL_Rect* clip) {
    clip = &health_clip;
    SDL_Rect renderquad= {health_rect.x, health_rect.y, health_clip.w , health_clip.h};
     // bao gom thong tin ve vi tri tam anh va kich thuoc cua tam anh

    SDL_RenderCopy(screen, health_object, clip, &renderquad); // day toan bo thong so cua p_object vao des voi kich thuoc va vi tri da luu trong bien rederquad
}

void Health::InitHealth(SDL_Renderer* screen)
{
    LoadImg("Pic/HealthBar.png", screen);
    Set_Rect(0, 10);
}

void Health::Free()
{
    if (health_object != NULL)
    {
        SDL_DestroyTexture(health_object);
        health_object = NULL;
        health_rect.w = 0;
        health_rect.h = 0;
    }
}
