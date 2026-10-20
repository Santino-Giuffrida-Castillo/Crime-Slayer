#pragma once
#include "Const.h"
#include <raylib.h>


struct LittleAsteroid
{
	Vector2 lookDir;
	Vector2 pos;
	Vector2 vel;
	float radius;
	bool isActive = false;

};

struct MidAsteroid
{
	LittleAsteroid littleAsteroids[2];
	Vector2 lookDir;
	Vector2 pos;
	Vector2 vel;
	float radius;
	bool isActive = false;

};

struct BigAsteroid
{
	MidAsteroid midAsteroids[2];
	Vector2 lookDir;
	Vector2 pos;
	Vector2 vel;
	float radius;
	bool isActive = false;
	
};

BigAsteroid initAsteroid();
MidAsteroid initMidAsteroid(BigAsteroid& asteroid, int index);
LittleAsteroid initLittleAsteroid(MidAsteroid& asteroid, int index);

void moveAsteroid(BigAsteroid asteroids[maxBullets]);
void moveAsteroid(MidAsteroid asteroids[2], int index);
void moveAsteroid(LittleAsteroid asteroids[2], int index);

void drawAsteroid(BigAsteroid asteroids[maxBullets]);
void drawAsteroid(MidAsteroid asteroids[2], int index);
void drawAsteroid(LittleAsteroid asteroids[2], int index);

void spawAsteroid(BigAsteroid asteroids[maxBullets], float& count);
void spawMidAsteroid(MidAsteroid asteroids[2], int index);
void spawLittleAsteroid(LittleAsteroid asteroids[2], int index);
