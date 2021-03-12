#include "game.hpp"

Projectile::Projectile() {
  m_Active = false;
  m_X = 0.0;
  m_Y = 0.0;
  m_VX = 0.0;
  m_VY = 0.0;

  SDL_Surface * tempSurface = IMG_Load( c_SpriteFile );
  if ( !tempSurface ) {
    printf( "Could not load file: %s\n", IMG_GetError() );
    return;
  }

  m_SpriteTexture = SDL_CreateTextureFromSurface( renderer, tempSurface );
  if ( !m_SpriteTexture ) {
    printf( "Could not create texture: %s\n", IMG_GetError() );
  }

  SDL_FreeSurface( tempSurface );
};

void Projectile::Move() {
  m_X += m_VX;
  m_Y += m_VY;
  m_TTL -= diff_time;

  if ( m_TTL <= 0 ) {
    m_Active = false;
    m_TTL = 0;
  }
};

void Projectile::Render() {
  dest.x = m_X;
  dest.y = m_Y;
  dest.w = c_Width;
  dest.h = c_Height;

  int return_val = SDL_RenderCopy( renderer, m_SpriteTexture, NULL, &dest );
  if ( return_val != 0 ) {
    printf( "SDL_Init failed: %s\n", SDL_GetError() );
  }
};

void Projectile::Launch( float x, float y, float dx, float dy ) {
  m_X = x;
  m_Y = y;
  m_VX = c_Velocity * dx;
  m_VY = c_Velocity * dy;
  m_TTL = c_AliveTime;
  m_Active = true;
};