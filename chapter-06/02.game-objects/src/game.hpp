#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <emscripten.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <vector>

#define SPRITE_FILE "sprites/Franchise.png"
#define MAX_VELOCITY 2.0
#define PI 3.14159
#define TWO_PI 6.28318

extern Uint32 last_time;
extern Uint32 last_frame_time;
extern Uint32 current_time;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Rect dest;
extern SDL_Texture* sprite_texture;
extern SDL_Event event;
extern bool left_key_down;
extern bool right_key_down;
extern bool up_key_down;
extern bool down_key_down;
extern bool space_key_down;
extern float delta_time;
extern int diff_time;

class PlayerShip {
  public:
    const char * s_SpriteFile = "sprites/Franchise.png";
    const Uint32 c_MinLaunchTime = 300;
    const int c_Width = 16;
    const int c_Height = 16;
    Uint32 m_LastLaunchTime;
    SDL_Texture * m_SpriteTexture;

    float m_X;
    float m_Y;
    float m_Rotation;
    float m_DX;
    float m_DY;
    float m_VX;
    float m_VY;

    PlayerShip();
    void RotateLeft();
    void RotateRight();
    void Accelerate();
    void Decelerate();
    void CapVelocity();
    void Move();
    void Render();
};
extern PlayerShip player;

class Projectile {
  public:
    const char * c_SpriteFile = "sprites/Projectile.png";
    const int c_Width = 8;
    const int c_Height = 8;
    SDL_Texture * m_SpriteTexture;
    bool m_Active;
    const float c_Velocity = 6.0;
    const float c_AliveTime = 2000;
    float m_TTL;
    float m_X;
    float m_Y;
    float m_VX;
    float m_VY;

    Projectile();
    void Move();
    void Render();
    void Launch( float x, float y, float dx, float dy );
};

class ProjectilePool {
  public:
    std::vector<Projectile*> m_ProjectileList;
    ProjectilePool();
    ~ProjectilePool();
    void MoveProjectiles();
    void RenderProjectiles();
    Projectile * GetFreeProjectile();
};
extern ProjectilePool * projectile_pool;

#endif