#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Const.h"
#include "Asteroid.h"

void initGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[maxBullets]);
void playGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[maxBullets], float& count);
void checkIfPlayerOutScreen(Player& player);
void checkIfBulletOutScreen(Bullet bullet[maxBullets]);
void checkIfBigAsteroidOutScreen(BigAsteroid asteroids[maxBullets]);
void checkIfMidAsteroidOutScreen(MidAsteroid asteroids[2], int index);
void checkIfLittleAsteroidOutScreen(LittleAsteroid asteroids[2], int index);