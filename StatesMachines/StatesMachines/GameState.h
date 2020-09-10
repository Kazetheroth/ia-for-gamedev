#pragma once

class GameState
{
	public:
		bool isDay;
		bool isHungry;
		bool isOutside;
		bool hasFood;

	GameState();
	GameState(bool isDay, bool isHungry, bool isGoingOut, bool isDirty, bool isReturningHome, bool hasFood);
};
