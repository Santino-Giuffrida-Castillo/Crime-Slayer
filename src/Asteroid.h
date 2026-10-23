#pragma once

#include <raylib.h>
namespace asteroids
{
	const int ASTEROID_SPEED = 300;
	const int MAX_ASTEROIDS = 30;
	struct LittleAsteroid
	{
		Vector2 lookDir;
		Vector2 pos;
		Vector2 vel;
		float radius;
		bool isActive = false;
		bool isHit = false;
		Sound explosionSound;
		Texture2D texture = { 0 };
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
	};

	struct MidAsteroid
	{
		LittleAsteroid littleAsteroids[2];
		Vector2 lookDir;
		Vector2 pos;
		Vector2 vel;
		float radius;
		bool isActive = false;
		bool isHit = false;
		Texture2D texture = { 0 };
		Sound explosionSound;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
	};

	struct BigAsteroid
	{
		MidAsteroid midAsteroids[2];
		Vector2 lookDir;
		Vector2 pos;
		Vector2 vel;
		float radius;
		bool isActive = false;
		bool isHit = false;
		Texture2D texture = { 0 };
		Sound explosionSound;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
	};

	BigAsteroid initAsteroid();
	MidAsteroid initMidAsteroid(BigAsteroid& asteroid, int index);
	LittleAsteroid initLittleAsteroid(MidAsteroid& asteroid, int index);

	void moveAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS]);
	void moveAsteroid(MidAsteroid asteroids[2], int index);
	void moveAsteroid(LittleAsteroid asteroids[2], int index);

	void drawAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS]);
	void drawAsteroid(MidAsteroid asteroids[2], int index);
	void drawAsteroid(LittleAsteroid asteroids[2], int index);

	void spawAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS], float& count);

	void loadAsteroidTextures();
	void unloadAsteroidTextures();

	void loadAsteroidSounds();
	void unloadAsteroidSounds();
	void playAsteroidExplosion(int num);
}