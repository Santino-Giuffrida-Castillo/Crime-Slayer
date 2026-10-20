#pragma once
#include "Player.h"
#include "Bullet.h"

void initGame(Player& player, Bullet& bullet);
void playGame(Player& player, Bullet& bullet);
void checkIfPlayerOutScreen(Player& player);