#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(bool isDay, bool isHungry, bool isOutside, bool hasFood)
{
	this->isDay = isDay;
	this->isHungry = isHungry;
	this->isOutside = isOutside;
	this->hasFood = hasFood;
}
